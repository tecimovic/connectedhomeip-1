/***************************************************************************//**
 * @file
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef ZCL_SCENES_SERVER_TOKENS_H
#define ZCL_SCENES_SERVER_TOKENS_H

/**
 * Custom Application Tokens
 */

#include "scenes-server.h"

// Defines for Scenes tokens (if using Token based scene storage)
// Note: each cluster plugin has its own scenes sub-table structure.
#define CREATOR_ZCL_CORE_SCENES_NUM_ENTRIES   0x7A73
#define CREATOR_ZCL_CORE_SCENE_TABLE          0x7A74

#ifdef DEFINETOKENS
DEFINE_BASIC_TOKEN(ZCL_CORE_SCENES_NUM_ENTRIES,
                   uint8_t,
                   0x00)
DEFINE_INDEXED_TOKEN(ZCL_CORE_SCENE_TABLE,
                     EmberZclSceneEntry_t,
                     EMBER_AF_PLUGIN_SCENES_SERVER_TABLE_SIZE,
                     { EMBER_ZCL_SCENE_NULL, })
#endif // DEFINETOKENS

#endif // ZCL_SCENES_SERVER_TOKENS_H
