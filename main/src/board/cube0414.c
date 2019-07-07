/*
 * cube0414.c
 *
 *  Created on: 2018-03-16 16:15
 *      Author: Jack Chen <redchenjs@live.com>
 */

#include <string.h>

#include "esp_log.h"

#include "driver/gpio.h"
#include "driver/spi_master.h"

#include "chip/spi.h"
#include "board/cube0414.h"

#ifdef CONFIG_VFX_OUTPUT_CUBE0414

#define TAG "cube0414"

spi_transaction_t hspi_trans[2];

void cube0414_init_board(void)
{
    gpio_set_direction(CONFIG_LIGHT_CUBE_DC_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_LIGHT_CUBE_DC_PIN, 0);

    memset(hspi_trans, 0, sizeof(hspi_trans));

    ESP_LOGI(TAG, "initialized, dc: %d", CONFIG_LIGHT_CUBE_DC_PIN);
}

void cube0414_setpin_dc(spi_transaction_t *t)
{
    int dc = (int)t->user;
    gpio_set_level(CONFIG_LIGHT_CUBE_DC_PIN, dc);
}

void cube0414_write_cmd(uint8_t cmd)
{
    hspi_trans[0].length = 8;
    hspi_trans[0].tx_buffer = &cmd;
    hspi_trans[0].user = (void*)0;

    spi_device_transmit(hspi, &hspi_trans[0]);
}

void cube0414_write_data(uint8_t data)
{
    hspi_trans[0].length = 8;
    hspi_trans[0].tx_buffer = &data;
    hspi_trans[0].user = (void*)1;

    spi_device_transmit(hspi, &hspi_trans[0]);
}

void cube0414_refresh_gram(uint8_t *gram)
{
    hspi_trans[0].length = 8,
    hspi_trans[0].tx_data[0] = 0xda;    // Write Frame Data
    hspi_trans[0].user = (void*)0;
    hspi_trans[0].flags = SPI_TRANS_USE_TXDATA;

    hspi_trans[1].length = 8*8*8*24;   // 8x8x8x24bit
    hspi_trans[1].tx_buffer = gram;
    hspi_trans[1].user = (void*)1;

    // Queue all transactions.
    for (int x=0; x<2; x++) {
        spi_device_queue_trans(hspi, &hspi_trans[x], portMAX_DELAY);
    }
}
#endif
