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

#ifndef ZCL_DOOR_LOCK_SERVER_H
#define ZCL_DOOR_LOCK_SERVER_H

#include EMBER_AF_API_ZCL_CORE

// Define Door Lock plugin Scenes sub-table structure.
// NOTE: When modifying this structure take into account NVM token space and
// backward compatibility considerations
typedef struct {
  bool hasLockStateValue;
  uint8_t lockStateValue;
} EmZclDoorLockSceneSubTableEntry_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_EVENT_SOURCE_KEYPAD        = 0x00,
  EMBER_ZCL_DOOR_LOCK_EVENT_SOURCE_RF            = 0x01,
  EMBER_ZCL_DOOR_LOCK_EVENT_SOURCE_MANUAL        = 0x02,
  EMBER_ZCL_DOOR_LOCK_EVENT_SOURCE_RFID          = 0x03,
  EMBER_ZCL_DOOR_LOCK_EVENT_SOURCE_INDETERMINATE = 0xFF,
} EmberAfDoorLockEventSource_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_EVENT_TYPE_OPERATION   = 0x00,
  EMBER_ZCL_DOOR_LOCK_EVENT_TYPE_PROGRAMMING = 0x01,
  EMBER_ZCL_DOOR_LOCK_EVENT_TYPE_ALARM       = 0x02,
} EmberAfDoorLockEventType_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_NORMAL_MODE            = 0x00,
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_VACATION_MODE          = 0x01,
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_PRIVACY_MODE           = 0x02,
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_NO_RF_LOCK_OR_UNLOCK   = 0x03,
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_LOCAL_PROGRAMMING_MODE = 0x04,
  EMBER_ZCL_DOOR_LOCK_OPERATING_MODE_PASSAGE_MODE           = 0x05,
} EmberAfDoorLockOperatingMode_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_UNKNOWN_OR_MFG_SPECIFIC  = 0x00,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_LOCK                     = 0x01,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_UNLOCK                   = 0x02,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_LOCK_INVALID_PIN_OR_ID   = 0x03,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_LOCK_INVALID_SCHEDULE    = 0x04,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_UNLOCK_INVALID_PIN_OR_ID = 0x05,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_UNLOCK_INVALID_SCHEDULE  = 0x06,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_ONE_TOUCH_LOCK           = 0x07,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_KEY_LOCK                 = 0x08,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_KEY_UNLOCK               = 0x09,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_AUTO_LOCK                = 0x0A,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_SCHEDULE_LOCK            = 0x0B,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_SCHEDULE_UNLOCK          = 0x0C,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_MANUAL_LOCK              = 0x0D,
  EMBER_ZCL_DOOR_LOCK_OPERATION_EVENT_CODE_MANUAL_UNLOCK            = 0x0E,
} EmberAfDoorLockOperationEventCode_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_UNKNOWN_OR_MFG_SPECIFIC = 0x00,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_MASTER_CODE_CHANGED     = 0x01,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_PIN_ADDED               = 0x02,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_PIN_DELETED             = 0x03,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_PIN_CHANGED             = 0x04,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_ID_ADDED                = 0x05,
  EMBER_ZCL_DOOR_LOCK_PROGRAMMING_EVENT_CODE_ID_DELETED              = 0x06,
} EmberAfDoorLockProgrammingEventCode_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_SECURITY_LEVEL_NETWORK_SECURITY = 0x00,
  EMBER_ZCL_DOOR_LOCK_SECURITY_LEVEL_APS_SECURITY     = 0x01,
} EmberAfDoorLockSecurityLevel_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_SET_PIN_OR_ID_STATUS_SUCCESS              = 0x00,
  EMBER_ZCL_DOOR_LOCK_SET_PIN_OR_ID_STATUS_GENERAL_FAILURE      = 0x01,
  EMBER_ZCL_DOOR_LOCK_SET_PIN_OR_ID_STATUS_MEMORY_FULL          = 0x02,
  EMBER_ZCL_DOOR_LOCK_SET_PIN_OR_ID_STATUS_DUPLICATE_CODE_ERROR = 0x03,
} EmberAfDoorLockSetPinOrIdStatus_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_SOUND_VOLUME_SILENT = 0x00,
  EMBER_ZCL_DOOR_LOCK_SOUND_VOLUME_LOW    = 0x01,
  EMBER_ZCL_DOOR_LOCK_SOUND_VOLUME_HIGH   = 0x02,
} EmberAfDoorLockSoundVolume_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_STATE_NOT_FULLY_LOCKED = 0x00,
  EMBER_ZCL_DOOR_LOCK_STATE_LOCKED           = 0x01,
  EMBER_ZCL_DOOR_LOCK_STATE_UNLOCKED         = 0x02,
} EmberAfDoorLockState_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_TYPE_DEAD_BOLT      = 0x00,
  EMBER_ZCL_DOOR_LOCK_TYPE_MAGNETIC       = 0x01,
  EMBER_ZCL_DOOR_LOCK_TYPE_MORTISE        = 0x02,
  EMBER_ZCL_DOOR_LOCK_TYPE_RIM            = 0x03,
  EMBER_ZCL_DOOR_LOCK_TYPE_LATCH_BOLT     = 0x04,
  EMBER_ZCL_DOOR_LOCK_TYPE_CYLINDRICAL    = 0x05,
  EMBER_ZCL_DOOR_LOCK_TYPE_TUBULAR        = 0x06,
  EMBER_ZCL_DOOR_LOCK_TYPE_INTERCONNECTED = 0x07,
  EMBER_ZCL_DOOR_LOCK_TYPE_DEAD_LATCH     = 0x08,
  EMBER_ZCL_DOOR_LOCK_TYPE_OTHER          = 0x09,
} EmberAfDoorLockType_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_USER_STATUS_AVAILABLE         = 0x00,
  EMBER_ZCL_DOOR_LOCK_USER_STATUS_OCCUPIED_ENABLED  = 0x01,
  EMBER_ZCL_DOOR_LOCK_USER_STATUS_OCCUPIED_DISABLED = 0x03,
  EMBER_ZCL_DOOR_LOCK_USER_STATUS_NOT_SUPPORTED     = 0xFF,
} EmberAfDoorLockUserStatus_t;

typedef enum {
  EMBER_ZCL_DOOR_LOCK_USER_TYPE_UNRESTRICTED       = 0x00,
  EMBER_ZCL_DOOR_LOCK_USER_TYPE_ONE_TIME_USER      = 0x01,
  EMBER_ZCL_DOOR_LOCK_USER_TYPE_USER_WITH_SCHEDULE = 0x02,
  EMBER_ZCL_DOOR_LOCK_USER_TYPE_MASTER_USER        = 0x03,
  EMBER_ZCL_DOOR_LOCK_USER_TYPE_NOT_SUPPORTED      = 0xFF,
} EmberAfDoorLockUserType_t;

typedef enum {
  EMBER_ZCL_DOOR_STATE_OPEN              = 0x00,
  EMBER_ZCL_DOOR_STATE_CLOSED            = 0x01,
  EMBER_ZCL_DOOR_STATE_ERROR_JAMMED      = 0x02,
  EMBER_ZCL_DOOR_STATE_ERROR_FORCED_OPEN = 0x03,
  EMBER_ZCL_DOOR_STATE_ERROR_UNSPECIFIED = 0x04,
} EmberAfDoorState_t;

typedef struct {
  EmberAfDoorLockUserStatus_t status;
  EmberAfDoorLockUserType_t type;
  uint8_t pinLength;
  uint8_t pinData[EMBER_AF_PLUGIN_DOOR_LOCK_SERVER_DOOR_LOCK_MAX_PIN_LENGTH];
} EmberAfDoorLockUser_t;

typedef struct {
  uint16_t userId;
  uint8_t daysMask;
  uint8_t startHour;
  uint8_t startMinute;
  uint8_t stopHour;
  uint8_t stopMinute;
} EmberAfDoorLockScheduleEntry_t;

#endif // ZCL_DOOR_LOCK_SERVER_H
