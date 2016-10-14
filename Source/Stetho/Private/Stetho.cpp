//
//  Created by Robert Segal on 2016-03-31.
//  Copyright (c) 2016 Get Set Games Inc. All rights reserved.
//

#include "StethoPrivatePCH.h"
#include "StethoSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogStetho);

#define LOCTEXT_NAMESPACE "Stetho"

class FStetho : public IStetho
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FStetho, Stetho )

void FStetho::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Stetho",
										 LOCTEXT("RuntimeSettingsName", "Stetho"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Stetho plugin"),
										 GetMutableDefault<UStethoSettings>()
										 );
	}
}


void FStetho::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
