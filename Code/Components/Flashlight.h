#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <DefaultComponents/Lights/ProjectorLightComponent.h>
#include <DefaultComponents/Input/InputComponent.h>

// Flash light

class CFlashlight final : public IEntityComponent
{

	

public:
	CFlashlight() = default;
	virtual ~CFlashlight() = default;
	static constexpr EEntityAspects FlashlightAspect = eEA_GameClientA;
	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual void Initialize() override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int flags) override;
	bool IsLocalClient() const { return (m_pEntity->GetFlags() & ENTITY_FLAG_LOCAL_PLAYER) != 0; }
	virtual NetworkAspectType GetNetSerializeAspectMask() const override { return FlashlightAspect; }
	void turnOnOff();
	Cry::DefaultComponents::CInputComponent* m_pInputComponent = nullptr;
	Cry::DefaultComponents::CProjectorLightComponent* m_projectorLight = nullptr;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CFlashlight>& desc)
	{
		desc.SetGUID("{AA946D44-421F-4866-AC8A-54CF0A5F6429}"_cry_guid);
		desc.SetEditorCategory("Weapon");
		desc.SetLabel("Flashlight");
		desc.SetDescription("");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });
	}

protected:
	bool m_lightOn = true;
};

