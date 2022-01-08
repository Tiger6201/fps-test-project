#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <DefaultComponents/Physics/RigidBodyComponent.h>
#include <DefaultComponents/Geometry/StaticMeshComponent.h>

class CSoda final : public IEntityComponent
{

protected:
	Cry::DefaultComponents::CRigidBodyComponent* rigidBodyComponent = nullptr;
	Cry::DefaultComponents::CStaticMeshComponent* staticMeshComponent = nullptr;

public:
	CSoda() = default;
	virtual ~CSoda() = default;

	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual void Initialize() override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;

	static void ReflectType(Schematyc::CTypeDesc<CSoda>& desc)
	{
		desc.SetGUID("{7DDBA898-039A-49EE-AEEC-72B05FEF7873}"_cry_guid);
		desc.SetEditorCategory("items");
		desc.SetLabel("Soda");
		desc.SetDescription("");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });
	}



};

