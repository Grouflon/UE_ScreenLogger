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
	
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print warnings duration") float printWarningDuration = 1.5f;
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print errors duration") float printErrorsDuration = 1.5f;
	
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print warning color") FColor printWarningColor = FColor::Yellow;
	UPROPERTY(Config, EditAnywhere, DisplayName = "Print errors color") FColor printErrorColor = FColor::Red;
};
