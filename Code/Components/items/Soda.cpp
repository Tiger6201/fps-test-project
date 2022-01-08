#include "StdAfx.h"
#include "Soda.h"

#include <CrySchematyc/Reflection/TypeDesc.h>
#include <CrySchematyc/Utils/EnumFlags.h>
#include <CrySchematyc/Env/IEnvRegistry.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/Elements/EnvFunction.h>
#include <CrySchematyc/Env/Elements/EnvSignal.h>
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc/MathTypes.h>
#include <CrySchematyc/Utils/SharedString.h>
#include <CryCore/StaticInstanceList.h>


static void RegisterCSoda(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSoda));
	}
}


void CSoda::Initialize()
{
	rigidBodyComponent = GetEntity()->GetOrCreateComponent<Cry::DefaultComponents::CRigidBodyComponent>();
	staticMeshComponent = GetEntity()->GetOrCreateComponent<Cry::DefaultComponents::CStaticMeshComponent>();
	staticMeshComponent->SetFilePath("Objects/props/soda/soda_can_a.cgf");
	staticMeshComponent->LoadFromDisk();
	staticMeshComponent->ResetObject();
	rigidBodyComponent->m_isNetworked = true;
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCSoda)


Cry::Entity::EventFlags CSoda::GetEventMask() const
{
	return
		Cry::Entity::EEvent::Update;
}
void CSoda::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::Update:
	{

	}
	break;
	}
}
