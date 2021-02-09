/*
 * bt_av.h
 *
 *  Created on: 2019-04-29 12:31
 *      Author: Jack Chen <redchenjs@live.com>
 */

#ifndef INC_USER_BT_AV_H_
#define INC_USER_BT_AV_H_

#include <stdint.h>

#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"

extern esp_bd_addr_t a2d_remote_bda;
extern unsigned int a2d_sample_rate;

extern void bt_app_avrc_ct_cb(esp_avrc_ct_cb_event_t event, esp_avrc_ct_cb_param_t *param);
extern void bt_app_a2d_cb(esp_a2d_cb_event_t event, esp_a2d_cb_param_t *param);
extern void bt_app_a2d_data_cb(const uint8_t *data, uint32_t len);

#endif /* INC_USER_BT_AV_H_*/
