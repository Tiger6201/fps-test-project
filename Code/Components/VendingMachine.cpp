#include "StdAfx.h"
#include "VendingMachine.h"

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
#include <CryNetwork/Rmi.h>
#include <CryExtension/CryGUID.h>


static void RegisterCVendingMachine(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CVendingMachine));
	}
}


void CVendingMachine::Initialize()
{
	SRmi<RMI_WRAP(&CVendingMachine::spawnEntity)>::Register(this, eRAT_NoAttach, false, eNRT_ReliableOrdered);

	m_pEntity->GetNetEntity()->BindToNetwork();
	m_pInputComponent = m_pEntity->GetOrCreateComponent<Cry::DefaultComponents::CInputComponent>();
	m_pInputComponent->RegisterAction("player", "useVendingMachine", [this](int activationMode, float value) {
		if (activationMode == 2) {
			SRmi<RMI_WRAP(&CVendingMachine::spawnEntity)>::InvokeOnServer(this, RemoteSpawnEntityParams{});
		}

		});

	m_pInputComponent->BindAction("player", "useVendingMachine", eAID_KeyboardMouse, EKeyId::eKI_F);
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCVendingMachine)


Cry::Entity::EventFlags CVendingMachine::GetEventMask() const
{
	return
		Cry::Entity::EEvent::Update;
}
void CVendingMachine::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::Update:
	{

	}
	break;
	}
}

bool CVendingMachine::NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int flags)
{

	return true;
}

bool CVendingMachine::spawnEntity(RemoteSpawnEntityParams&& params, INetChannel* pNetChannel)
{
	//spawn entity

	SEntitySpawnParams spawnParams;
	spawnParams.pClass = gEnv->pEntitySystem->GetClassRegistry()->GetDefaultClass();

	if (IEntity* pEntity = gEnv->pEntitySystem->SpawnEntity(spawnParams))
	{
		pEntity->SetPos(GetEntity()->GetWorldPos());
		pEntity->LoadGeometry(0, "Objects/props/soda/soda_can_a.cgf");
		pEntity->GetOrCreateComponent<Cry::DefaultComponents::CRigidBodyComponent>();
		pEntity->GetNetEntity()->BindToNetwork();
	}

	return true;
}