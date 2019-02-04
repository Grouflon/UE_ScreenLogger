#include "OnScreenOutputDevice.h"

#include <Engine/Engine.h>
#include <ScreenLoggerSettings.h>


void FOnScreenOutputDevice::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const FName& Category)
{
	if (GEngine)
	{
		if (Verbosity == ELogVerbosity::Error && GetMutableDefault<UScreenLoggerSettings>()->bPrintErrors)
		{
			GEngine->AddOnScreenDebugMessage(-1, GetMutableDefault<UScreenLoggerSettings>()->printDuration, FColor::Red, V);
		}
		else if (Verbosity == ELogVerbosity::Warning && GetMutableDefault<UScreenLoggerSettings>()->bPrintWarnings)
		{
			GEngine->AddOnScreenDebugMessage(-1, GetMutableDefault<UScreenLoggerSettings>()->printDuration, FColor::Yellow, V);
		}
		else if ((Verbosity == ELogVerbosity::Display || Verbosity == ELogVerbosity::Log) && GetMutableDefault<UScreenLoggerSettings>()->bPrintLogs)
		{
			GEngine->AddOnScreenDebugMessage(-1, GetMutableDefault<UScreenLoggerSettings>()->printDuration, FColor::White, V);
		}
	}
}
