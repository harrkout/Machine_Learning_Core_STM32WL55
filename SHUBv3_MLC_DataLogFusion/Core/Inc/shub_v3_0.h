/*  ******************************************************************************\
 * /------------------------------------------------------------------------------/
 * |-- Title      : Sensor Hub v3.0 driver
 * |-- Project    : General
 * |#----------------------------------------------------------------------------#
 * |-- File       : shub_v3-0.h
 * |-- Author     : Othon Tomoutzoglou  <otto@hmu.gr>, Dimitris Bakoyiannis <dbakoyiannis@hmu.gr>
 * |-- Company    : Hellenic Mediterranean University, department of
 * |--              Electrical & Computer Engineering, ISCA-lab
 * |-- URL        : https://isca.hmu.gr/
 * |-- Created    : 2022-06-16
 * |-- Last update:
 * |-- License    :
 * |--   This program is free software: you can redistribute it and/or modify
 * |--   it under the terms of the GNU General Public License as published by
 * |--   the Free Software Foundation, either version 3 of the License, or
 * |--   (at your option) any later version.
 * |--
 * |--   This program is distributed in the hope that it will be useful,
 * |--   but WITHOUT ANY WARRANTY; without even the implied warranty of
 * |--   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * |--   GNU General Public License for more details.
 * |--
 * |--   You should have received a copy of the GNU General Public License
 * |--   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * |--
 * |-- Platform   : NUCLEO-WL55JC1
 * |-- Standard   : ISO C11 + GNU extensions
 * |#----------------------------------------------------------------------------#
 * |-- Description: Library to interact with Sensor Hub v3,
 * |                i.e., {en/dis}able ports - interact with connected sensors
 * |#----------------------------------------------------------------------------#
 * |-- Copyright (c) 2022
 * |#----------------------------------------------------------------------------#
 * |-- Revisions  :
 * |-- Date        Version  Author  Description
 * |-- 2022-10-14  1.0              Created
 * \#-----------------------------------------------------------------------------\
 * *******************************************************************************/

#ifndef SHUB_V3_0_H_
#define SHUB_V3_0_H_


#include "stdint.h"

#define SHUB_INIT_I2C           1U
#define ASCII_TAB               0x09
#define ASCII_SPACE             0x20
#define ASCII_CR                0x0D

void shub_init(void);
void shub_power_i2c_mlc_on();
void shub_power_i2c_mlc_off();

#endif /* SHUB_V3_0_H_ */
