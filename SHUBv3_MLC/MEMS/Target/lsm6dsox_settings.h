/**
  ******************************************************************************
  * @file    lsm6dsox_settings.h
  * @author  MEMS Application Team
  * @brief   This file contains definitions for the LSM6DSOX settings
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LSM6DSOX_SETTINGS_H__
#define __LSM6DSOX_SETTINGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LSM6DSOX_ACC_ODR 104.0f /* ODR = 104Hz */

#define LSM6DSOX_ACC_FS 2 /* FS = 2g */

#define LSM6DSOX_GYRO_ODR 104.0f /* ODR = 104Hz */

#define LSM6DSOX_GYRO_FS 2000 /* FS = 2000dps */

#ifdef __cplusplus
}
#endif

#endif /* __LSM6DSOX_SETTINGS_H__*/

