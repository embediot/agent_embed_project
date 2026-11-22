# 代理说明

跟做本工程时，先读并遵守 [`.cursor/rules/esp-idf.mdc`](.cursor/rules/esp-idf.mdc)。

要点：

- 芯片 ESP32-S3，开发板 ESP32-S3-DevKitC-1，target `esp32s3`
- ESP-IDF 钉死为 v5.5.6，状态是已验证，日志要点见 `README.md`
- 只运行 `idf.py set-target esp32s3`（目标已经钉住时可以不重复执行）和 `idf.py build`
- 先构建并确认失败，再只改 `main/main.c` 里那一处调用，然后再构建
- 构建结束后，由人审阅产生的 diff。读者不需要自己动手输入编译命令
- 不要烧录，不要整片擦除，不要加 CI 或烧录脚本
