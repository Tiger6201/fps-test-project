#include "StdAfx.h"
#include "Flashlight.h"

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

static void RegisterCFlashlight(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CFlashlight));
	}
}

 
void CFlashlight::Initialize()
{
	SEntitySpawnParams spawnParams;
	spawnParams.pClass = gEnv->pEntitySystem->GetClassRegistry()->GetDefaultClass();

	if (IEntity* pEntity = gEnv->pEntitySystem->SpawnEntity(spawnParams))
	{
		m_projectorLight = pEntity->GetOrCreateComponent<Cry::DefaultComponents::CProjectorLightComponent>();
	}

		m_pEntity->GetNetEntity()->BindToNetwork();
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCFlashlight)


Cry::Entity::EventFlags CFlashlight::GetEventMask() const
{
	return
		Cry::Entity::EEvent::Update;
}
void CFlashlight::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::Update:
	{
		m_projectorLight->Enable(m_lightOn);
		updateFlashlightPos();
	}
	break;
	case Cry::Entity::EEvent::Reset:
	{

	}
	break;
	}
}

bool CFlashlight::NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int flags)
{
	if(aspect == FlashlightAspect)
	{
		ser.BeginGroup("flashlight");

		ser.Value("m_lightOn", m_lightOn, 'bool');

		ser.EndGroup();
	}

	return true;
}

void CFlashlight::turnOnOff() {
	m_lightOn = !m_lightOn;
} 

void CFlashlight::setAttachment(IAttachment* flashLightAttachment) {
	m_attachment = flashLightAttachment;
}

void CFlashlight::updateFlashlightPos() {
	if (m_attachment && m_projectorLight) {
			QuatTS location = m_attachment->GetAttWorldAbsolute();
			m_projectorLight->SetTransformMatrix(Matrix34::Create(Vec3(1, 1, 1), location.q, location.t));		
	}
}