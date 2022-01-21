#pragma once

#include <CryEntitySystem/IEntitySystem.h>

// this component is use to interact with entities(items, doors, elevators)

class CUse final : public IEntityComponent
{

protected:


public:
	CUse() = default;
	virtual ~CUse() = default;
	void Use();
	bool bUse = false;
	const char *UIMsg = "use";
	virtual void Initialize() override;
	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;

	static void ReflectType(Schematyc::CTypeDesc<CUse>& desc)
	{
		desc.SetGUID("{F84B5BBB-4DB1-4C8A-AD55-6FF90CD1A4D4}"_cry_guid);
		desc.SetEditorCategory("Game");
		desc.SetLabel("Use");
		desc.SetDescription("");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });
	}



};

