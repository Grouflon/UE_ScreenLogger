// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ScreenLogger.h"

#include <ISettingsModule.h>
#include <ISettingsSection.h>
#include <ScreenLoggerSettings.h>
#include <OnScreenOutputDevice.h>

#define LOCTEXT_NAMESPACE "FScreenLoggerModule"

void FScreenLoggerModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		ISettingsSectionPtr GameSettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "ScreenLogger",
			LOCTEXT("ScreenLoggerName", "Screen Logger"),
			LOCTEXT("ScreenLoggerDescription", "Configure Screen Logger."),
			GetMutableDefault<UScreenLoggerSettings>()
		);
	}

	m_outputDevice = new FOnScreenOutputDevice;
	GLog->AddOutputDevice(m_outputDevice);
}

void FScreenLoggerModule::ShutdownModule()
{
	GLog->RemoveOutputDevice(m_outputDevice);
	delete m_outputDevice;
	m_outputDevice = nullptr;

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ScreenLogger");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FScreenLoggerModule, ScreenLogger)