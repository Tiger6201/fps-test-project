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
#include <CryPhysics/physinterface.h>
#include "items/Soda.h"

static void RegisterCVendingMachine(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CVendingMachine));
	}
}


void CVendingMachine::Initialize()
{
	m_pRigidBodyComponent = GetEntity()->GetOrCreateComponent<Cry::DefaultComponents::CRigidBodyComponent>();
	m_pRigidBodyComponent->m_type = Cry::DefaultComponents::CRigidBodyComponent::EPhysicalType::Static;
	m_pStaticMeshComponent = GetEntity()->GetOrCreateComponent<Cry::DefaultComponents::CStaticMeshComponent>();
	m_pStaticMeshComponent->SetFilePath("Objects/interaction items/vending/vending.cgf");
	m_pStaticMeshComponent->LoadFromDisk();
	m_pStaticMeshComponent->ResetObject();
	SRmi<RMI_WRAP(&CVendingMachine::spawnEntity)>::Register(this, eRAT_NoAttach, false, eNRT_ReliableOrdered);

	m_pEntity->GetNetEntity()->BindToNetwork();
	m_pInputComponent = m_pEntity->GetOrCreateComponent<Cry::DefaultComponents::CInputComponent>();

	pUse = m_pEntity->GetOrCreateComponent<CUse>();

	
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
		if (pUse->bUse) {
			pUse->bUse = false;
			UseVendingMachine();
		}
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

		pEntity->SetPos(GetEntity()->GetWorldPos() + Vec3{ -0.111, -0.67, 0.6216 });
		pEntity->SetRotation(Quat::CreateRotationXYZ(Ang3 { 0, 80, 0 }));

		pEntity->CreateComponent<CSoda>();
		pEntity->GetNetEntity()->BindToNetwork();
	}

	return true;
}

void CVendingMachine::UseVendingMachine() {
	SRmi<RMI_WRAP(&CVendingMachine::spawnEntity)>::InvokeOnServer(this, RemoteSpawnEntityParams{});
}