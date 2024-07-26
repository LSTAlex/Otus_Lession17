#include "DamageActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include "IDamageInterface.h"

// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create box collision
	BoxOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxOverlap"));
	BoxOverlap->SetupAttachment(GetRootComponent());
	BoxOverlap->SetBoundsScale(3.f);
	BoxOverlap->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxOverlap->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECR_Overlap);

	//Create mesh and attach root
	DamageActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DamageActorMesh"));
	DamageActorMesh->SetupAttachment(BoxOverlap);
	DamageActorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();

	BoxOverlap->OnComponentBeginOverlap.AddDynamic(this, &ADamageActor::OnBoxOverlap);
	
}

// Called every frame
void ADamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamageActor::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool BFromSweep, const FHitResult& HitResult)
{
	if (OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_OnDamage(OtherActor,10.f);
	}
	Destroy();
}

