#!/bin/bash
st-flash --reset write build/stm32_f411xe_min_require.bin 0x8000000
