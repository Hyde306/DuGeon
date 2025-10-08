#include "ThirdPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

AThirdPersonCharacter::AThirdPersonCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
    Camera->bUsePawnControlRotation = false;

    bUseControllerRotationYaw = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    Camera->bUsePawnControlRotation = false;
}

void AThirdPersonCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AThirdPersonCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AThirdPersonCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &AThirdPersonCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AThirdPersonCharacter::LookUp);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AThirdPersonCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AThirdPersonCharacter::StopJump);
}

void AThirdPersonCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void AThirdPersonCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AThirdPersonCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AThirdPersonCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void AThirdPersonCharacter::StartJump()
{
    Jump();
}

void AThirdPersonCharacter::StopJump()
{
    StopJumping();
}