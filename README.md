# agent_embed_project

《AI Agent × 嵌入式工作流》样章用的可克隆最小 ESP-IDF 工程。演示「编译失败 → 改一处 → 编译通过」。

## 版本

钉死 **ESP-IDF v5.5.6**（发布标签 `v5.5.6`，2026-10-16，5.5 的稳定小版本）。不要改用「最新版」。

发布页：<https://github.com/espressif/esp-idf/releases/tag/v5.5.6>

文档：<https://docs.espressif.com/projects/esp-idf/en/v5.5.6/esp32s3/get-started/index.html>

状态：**已验证**。已在本环境安装 v5.5.6，并跑通「编译失败 → 只改一行 → 编译通过」。没有烧录开发板。

失败要点（`idf.py build` 退出码 2，唯一错误）：

```text
main/main.c:16:5: error: too few arguments to function 'app_wait_ready'
   16 |     app_wait_ready();
main/main.c:7:13: note: declared here
    7 | static void app_wait_ready(int delay_ms)
```

通过要点（同一工具链，`IDF_VER=v5.5.6`，`xtensa-esp32s3-elf-gcc`，退出码 0）：

```text
Successfully created esp32s3 image.
Project build complete.
```

生成 `build/agent_embed_project.elf`。`sdkconfig` 中为 `CONFIG_IDF_TARGET="esp32s3"`、`CONFIG_ESPTOOLPY_FLASHSIZE_8MB=y`。成功日志里的 `idf.py flash` 是 ESP-IDF 的固定提示，本演示不执行。

## 芯片与开发板

- 芯片：ESP32-S3
- IDF target：`esp32s3`
- 开发板：ESP32-S3-DevKitC-1
- `sdkconfig.defaults` 把 flash 设为 8 MB，对应这块开发板上常见的 ESP32-S3-WROOM-1

## 构建

在已导出 v5.5.6 的环境里，于工程根目录执行：

```bash
idf.py set-target esp32s3
idf.py build
```

跟做时由代理执行这两条命令。构建结束后，由人审阅产生的 diff。读者不需要自己动手输入编译命令。烧录和整片擦除不在本演示范围。

## 目录

```
CMakeLists.txt
sdkconfig.defaults
main/CMakeLists.txt
main/main.c
.gitignore
AGENTS.md
.cursor/rules/esp-idf.mdc
```

## 故意编不过

`main/main.c` 里 `app_wait_ready` 的定义要求一个 `int` 参数，`app_main` 里的调用没有传入这个参数。

编译器会报该函数参数过少，并指向这一行。修复应只改这一次调用，让参数个数和声明一致，并且是一行改动。不要改函数定义。

## 规则

- 规则文件：`.cursor/rules/esp-idf.mdc`
- `AGENTS.md` 指向该规则

规则用中文写，可复制到自己的 ESP-IDF 工程。复制前按规则文末「移植」修改版本、芯片、开发板和允许修改区。
