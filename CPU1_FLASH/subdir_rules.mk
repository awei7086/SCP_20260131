################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-708646097: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.18.1/sysconfig_cli.bat" --script "D:/WUJW/Ti Program/SCP/SCP(20260131)/c2000.syscfg" -o "syscfg" -s "C:/ti/c2000/C2000Ware_5_01_00_00/.metadata/sdk.json" -d "F28002x" --package 80QFP --part F28002x_80QFP --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-708646097 ../c2000.syscfg
syscfg/board.h: build-708646097
syscfg/board.cmd.genlibs: build-708646097
syscfg/board.opt: build-708646097
syscfg/pinmux.csv: build-708646097
syscfg/epwm.dot: build-708646097
syscfg/adc.dot: build-708646097
syscfg/c2000ware_libraries.cmd.genlibs: build-708646097
syscfg/c2000ware_libraries.opt: build-708646097
syscfg/c2000ware_libraries.c: build-708646097
syscfg/c2000ware_libraries.h: build-708646097
syscfg/clocktree.h: build-708646097
syscfg: build-708646097

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --opt_for_speed=2 --fp_mode=relaxed --fp_reassoc=on --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/driverlib/f28002x/driverlib" --include_path="D:/WUJW/Ti Program/DC2DC/BicD2D/h" --include_path="D:/WUJW/Ti Program/DC2DC/BicD2D/h/Lab" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/device" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --advice:performance=all --define=DEBUG --define=_FLASH --c89 --c++03 --relaxed_ansi --float_operations_allowed=all --printf_support=full --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/CPU1_FLASH/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --opt_for_speed=2 --fp_mode=relaxed --fp_reassoc=on --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/driverlib/f28002x/driverlib" --include_path="D:/WUJW/Ti Program/DC2DC/BicD2D/h" --include_path="D:/WUJW/Ti Program/DC2DC/BicD2D/h/Lab" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/device" --include_path="C:/ti/c2000/C2000Ware_5_01_00_00/driverlib/f28002x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --advice:performance=all --define=DEBUG --define=_FLASH --c89 --c++03 --relaxed_ansi --float_operations_allowed=all --printf_support=full --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/WUJW/Ti Program/SCP/SCP(20260131)/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


