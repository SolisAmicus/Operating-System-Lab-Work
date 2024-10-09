/*
 * Copyright (C) 2023-2024 Colin Ian King.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#ifndef CORE_INTERRUPTS_H
#define CORE_INTERRUPTS_H

#include "core-attribute.h"

extern void stress_interrupts_start(stress_interrupts_t *counters) NONNULL(1);
extern void stress_interrupts_stop(stress_interrupts_t *counters) NONNULL(1);
extern void stress_interrupts_check_failure(const char *name,
	stress_interrupts_t *counters, uint32_t instance, int *rc) NONNULL(1, 2, 4);
extern void stress_interrupts_dump(FILE *yaml, stress_stressor_t *stressors_list) NONNULL(2);

#endif