################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
appli/%.obj: ../appli/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/device_support/f28002x/headers/include" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/device" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=_FLASH --define=_LAUNCHXL_F280025C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="appli/$(basename $(<F)).d_raw" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/CPU1_LAUNCHXL_FLASH/syscfg" --obj_directory="appli" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


