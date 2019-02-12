
#include "OnScreenOutputDevice.h"

#include <Engine/Engine.h>
#include <ScreenLoggerSettings.h>


void FOnScreenOutputDevice::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const FName& Category)
{
	if (GEngine)
	{
		bool bPrintErrors   = GetMutableDefault<UScreenLoggerSettings>()->bPrintErrors;
		bool bPrintWarnings = GetMutableDefault<UScreenLoggerSettings>()->bPrintWarnings;
		bool bPrintLogs     = GetMutableDefault<UScreenLoggerSettings>()->bPrintLogs;

		float warningPrintTime = GetMutableDefault<UScreenLoggerSettings>()->printWarningDuration;
		float errorPrintTime   = GetMutableDefault<UScreenLoggerSettings>()->printErrorsDuration;

		FColor warningPrintColor = GetMutableDefault<UScreenLoggerSettings>()->printWarningColor;
		FColor errorPrintColor   = GetMutableDefault<UScreenLoggerSettings>()->printErrorColor;

		if (Verbosity == ELogVerbosity::Error && bPrintErrors)
		{
			GEngine->AddOnScreenDebugMessage(-1, errorPrintTime, errorPrintColor, V);
		}
		else if (Verbosity == ELogVerbosity::Warning && bPrintWarnings)
		{
			GEngine->AddOnScreenDebugMessage(-1, warningPrintTime, warningPrintColor, V);
		}
		else if ((Verbosity == ELogVerbosity::Display || Verbosity == ELogVerbosity::Log) && )
		{
			GEngine->AddOnScreenDebugMessage(-1, warningPrintTime, FColor::White, V);
		}
	}
}
