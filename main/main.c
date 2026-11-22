#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "agent_embed_project";

static void app_wait_ready(int delay_ms)
{
    vTaskDelay(pdMS_TO_TICKS(delay_ms));
}

void app_main(void)
{
    ESP_LOGI(TAG, "ESP32-S3-DevKitC-1 ready");
    /* 允许修改：这一处调用和函数声明的签名不一致，参数个数不对。 */
    app_wait_ready();
}
