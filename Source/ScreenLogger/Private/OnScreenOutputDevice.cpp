#include "OnScreenOutputDevice.h"

#include <Engine/Engine.h>
#include <ScreenLoggerSettings.h>


void FOnScreenOutputDevice::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const FName& Category)
{
	UScreenLoggerSettings* settings = GetMutableDefault<UScreenLoggerSettings>();
	if (!settings)
		return;

	if (GEngine)
	{

		if (Verbosity <= ScreenLoggerVerbosityToLogVerbosity(settings->PrintToScreenVerbosity))
		{
			FColor color = FColor::White;
			switch (Verbosity)
			{
			case ELogVerbosity::Fatal:
			case ELogVerbosity::Error:
				color = FColor::Red;
				break;
			case ELogVerbosity::Warning:
				color = FColor::Yellow;
			default:
				break;
			}

			GEngine->AddOnScreenDebugMessage(-1, settings->PrintToScreenDuration, color, V);
		}
	}
}
