// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScreenLoggerSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class SCREENLOGGER_API UScreenLoggerSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print Errors on screen") bool bPrintErrors = true;
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print Warnings on screen") bool bPrintWarnings = true;
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print Logs on screen") bool bPrintLogs = false;
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print duration") float printDuration = 1.5f;
};
