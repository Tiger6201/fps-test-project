#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <DefaultComponents/Input/InputComponent.h>

class CVendingMachine final : public IEntityComponent
{

protected:

	struct RemoteSpawnEntityParams
	{
		// Called once on the server to serialize data to the other clients
		// Then called once on the other side to deserialize
		void SerializeWith(TSerialize ser)
		{

		}


	};

	Cry::DefaultComponents::CInputComponent* m_pInputComponent = nullptr;

public:
	CVendingMachine() = default;
	virtual ~CVendingMachine() = default;
	static constexpr EEntityAspects vendingMachineAspect = eEA_GameClientA;
	bool spawnEntity(RemoteSpawnEntityParams&& params, INetChannel* pNetChannel);
	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual void Initialize() override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int flags) override;
	virtual NetworkAspectType GetNetSerializeAspectMask() const override { return vendingMachineAspect; }

	static void ReflectType(Schematyc::CTypeDesc<CVendingMachine>& desc)
	{
		desc.SetGUID("{067CD275-C9CC-46AE-8338-3316999DD913}"_cry_guid);
		desc.SetEditorCategory("interaction");
		desc.SetLabel("VendingMachine");
		desc.SetDescription("");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });
	}



};

