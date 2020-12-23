﻿#pragma once
#include "CoreMinimal.h"
#include "QEFactories.generated.h"

UCLASS(CustomConstructor)
class UQEFactoryNew : public UFactory
{
	GENERATED_BODY()
public:
	UQEFactoryNew(const FObjectInitializer& ObjectInitializer);
protected:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override { return true; }
public:
	static TMap<UClass*, UFunction*> NewFunctionMap;
	static TMap<UClass*, UClass*> SupportClassMap;
};

UCLASS(CustomConstructor)
class UQEFactoryFile : public UFactory
{
	GENERATED_BODY()
public:
	UQEFactoryFile(const FObjectInitializer& ObjectInitializer);
public:
	virtual void GetSupportedFileExtensions(TArray<FString>& OutExtensions) const override;
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
public:
	static TMap<UClass*, UFunction*> NewFunctionMap;
	static TMap<UClass*, UClass*> SupportClassMap;
};