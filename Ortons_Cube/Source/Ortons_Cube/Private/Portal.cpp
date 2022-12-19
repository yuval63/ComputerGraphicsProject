// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Orton.h"

// Sets default values
APortal::APortal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	// 7 x values 45000.0
	// 7 y values 0.0
	// 7 z values 6380.0

	player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());

	/***************************************************/
	/**                        W<->B                  **/
	/***************************************************/
	if ( FVector::Dist(GetActorLocation(),FVector(0.0f,0.0f,40920.0f)) < 500) {		// W->B
		portalID = 0;
		fromRoomID = 0;
		toRoomID = 1;
		to = FVector(0.0f, 300.0f, 6360.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 6360.0f)) < 500) {     // B->W
		portalID = 0;            
		fromRoomID = 1;
		toRoomID = 0;
		to = FVector(0.0f, 300.0f, 40920.0f);

	}



	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -9000.0f, 1310.0f)) < 500) {		// W->G
		portalID = 1;
		fromRoomID = 0;
		toRoomID = 10;
		to = FVector(0.0f, -36300.0f, 1310.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -36000.0f, 1310.0f)) < 500) {		//G->W
		portalID = 1;
		fromRoomID = 10;
		toRoomID = 0;
		to = FVector(0.0f, -8700.0f, 1310.0f);

	}







	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, -4080.0f)) < 500) {		// W->O 
		portalID = 2;
		fromRoomID = 0;
		toRoomID = 16;
		to = FVector(0.0f, 300.0f, -38640.0f);

	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, -38640.0f)) < 500) {		//O->W
		portalID = 2;
		fromRoomID = 16;
		toRoomID = 0;
		to = FVector(0.0f, 300.0f, -4080.0f);

	}






	if (FVector::Dist(GetActorLocation(), FVector(-9000.0f, 0.0f, 1310.0f)) < 500) {		// W->P
		portalID = 3;
		fromRoomID = 0;
		toRoomID = 22;
		to = FVector(-36300.0f, 0.0f, 1310.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(-36000.0f, 0.0f, 1310.0f)) < 500) {		//P->W
		portalID = 3;
		fromRoomID = 22;
		toRoomID = 0;
		to = FVector(-9000.0f, 0.0f, 1310.0f);

	}







	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 9000.0f, 1310.0f)) < 500) {		// W->R 
		portalID = 4;
		fromRoomID = 0;
		toRoomID = 24;
		to = FVector(0.0f, 36300.0f, 1310.0f);

	}
	if ( FVector::Dist(GetActorLocation(), FVector(0.0f, 36000.0f, 1310.0f)) < 500) {		// R->W
		portalID = 4;
		fromRoomID = 24;
		toRoomID = 0;
		to = FVector(0.0f, 8700.0f, 1310.0f);

	}



	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, 0.0f, 1310.0f)) < 500) {		// W->Y 
		portalID = 5;
		fromRoomID = 0;
		toRoomID = 26;
		to = FVector(36300.0f, 0.0f, 1310.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(36000.0f, 0.0f, 1310.0f)) < 500) {		//Y->W
		portalID = 5;
		fromRoomID = 26;
		toRoomID = 0;
		to = FVector(8700.0f, 0.0f, 1310.0f);

	}





	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -9000.0f, 46310.0f)) < 500) {		// B->BG 
		portalID = 6;
		fromRoomID = 1;
		toRoomID = 2;
		to = FVector(0.0f, -36300.0f, 46310.0f);			

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -36000.0f, 46310.0f)) < 500) {		//  BG->B    
		portalID = 6;
		fromRoomID = 2;
		toRoomID = 1;
		to = FVector(0.0f, -8700.0f, 46310.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(-9000.0f, 0.0f, 46310.0f)) < 500 ) {		// B->BP 
		portalID = 7;
		fromRoomID = 1;
		toRoomID = 5;
		to = FVector(-36300.0f, 0.0f, 46310.0f);

	}

	if (FVector::Dist(GetActorLocation(), FVector(-36000.0f, 0.0f, 46310.0f)) < 500) {		// BP->B 
		portalID = 7;
		fromRoomID = 5;
		toRoomID = 1;
		to = FVector(-8700.0f, 0.0f, 46310.0f);

	}





	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 9000.0f, 46310.0f)) < 500) {		// B->BR 
		portalID = 8;
		fromRoomID = 1;
		toRoomID = 7;
		to = FVector(0.0f, 36300.0f, 46310.0f);

	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 36000.0f, 46310.0f)) < 500) {		// BR->B      
		portalID = 8;
		fromRoomID = 7;
		toRoomID = 1;
		to = FVector(0.0f, 8700.0f, 46310.0f);

	}




	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, 0.0f, 46310.0f)) < 500 ) {		// B->BY
		portalID = 9;
		fromRoomID = 1;
		toRoomID = 9;
		to = FVector(36300.0f, 0.0f, 46310.0f);

	}
	if ( FVector::Dist(GetActorLocation(), FVector(36000.0f, 0.0f, 46310.0f)) < 500) {		// BY->B 
		portalID = 9;
		fromRoomID = 9;
		toRoomID = 1;
		to = FVector(8700.0f, 0.0f, 46310.0f);
	}




	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -45000.0f, 6380.0f)) < 500) {		// G->BG 
		portalID = 10;
		fromRoomID = 10;
		toRoomID = 2;
		to = FVector(0.0f, -44700.0f, 40920.0f);
	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -45000.0f, 40920.0f)) < 500) {		// BG->G   
		portalID = 10;
		fromRoomID = 10;
		toRoomID = 2;
		to = FVector(0.0f, -44700.0f, 6380.0f);
	}










	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -45000.0f, -4040.0f)) < 500) {		// G->GO 
		portalID = 11;
		fromRoomID = 10;
		toRoomID = 11;
		to = FVector(0.0f, -44700.0f, -38640.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -45000.0f, -38640.0f)) < 500) {		// GO->G     [needs to change the z]
		portalID = 11;
		fromRoomID = 11;
		toRoomID = 10;
		to = FVector(0.0f, -44700.0f, -4040.0f);

	}







	if (FVector::Dist(GetActorLocation(), FVector(-9000.0f, -45000.0f, 1310.0f)) < 500) {		// G->GP 
		portalID = 12;
		fromRoomID = 10;
		toRoomID = 14;
		to = FVector(-36300.0f, -45000.0f, 1310.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(-36000.0f, -45000.0f, 1310.0f)) < 500) {		// GP->G     
		portalID = 12;
		fromRoomID = 14;
		toRoomID = 10;
		to = FVector(-8700.0f, -45000.0f, 1310.0f);


	}











	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, -45000.0f, 1310.0f)) < 500) {		// G -> GY
		portalID = 13;
		fromRoomID = 10;
		toRoomID = 15;
		to = FVector(36300.0f, -45000.0f, 1310.0f);
	}
	if (FVector::Dist(GetActorLocation(), FVector(36000.0f, -45000.0f, 1310.0f)) < 500) {		// Gy-> G   
		portalID = 13;
		fromRoomID = 15;
		toRoomID = 10;
		to = FVector(8700.0f, -45000.0f, 1310.0f);

	}












	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -9000.0f, -43690.0f)) < 500) {		// O->GO
		portalID = 14;
		fromRoomID = 16;
		toRoomID = 11;
		to = FVector(0.0f, -36300.0f, -43690.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, -36000.0f, -43690.0f)) < 500) {		// GO->O
		portalID = 14;
		fromRoomID = 11;
		toRoomID = 16;
		to = FVector(0.0f, -8700.0f, -43690.0f);
	}




	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// O->OP
		portalID = 15;
		fromRoomID = 16;
		toRoomID = 17;
		to = FVector(0.0f, 0.0f, 0.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// OP->O
		portalID = 15;
		fromRoomID = 17;
		toRoomID = 16;
		to = FVector(0.0f, 0.0f, 0.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 9000.0f, -43690.0f)) < 500) {		// O->OR
		portalID = 16;
		fromRoomID = 16;
		toRoomID = 19;
		to = FVector(0.0f, 36300.0f, -43690.0f);
	}


	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 36000.0f, -43690.0f)) < 500) {		// OR->O
		portalID = 16;
		fromRoomID = 19;
		toRoomID = 16;
		to = FVector(0.0f, 8700.0f, -43690.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, 0.0f, -43690.0f)) < 500) {		// O->OY
		portalID = 17;
		fromRoomID = 16;
		toRoomID = 21;
		to = FVector(36300.0f, 0.0f, -43690.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(36000.0f, 0.0f, -43690.0f)) < 500) {		// OY->O  
		portalID = 17;
		fromRoomID = 21;
		toRoomID = 16;
		to = FVector(8700.0f, 0.0f, -43690.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 0.0f, 6380.0f)) < 500) {		// P->BP
		portalID = 18;
		fromRoomID = 22;
		toRoomID = 5;
		to = FVector(-45300.0f, 0.0f, 40920.0f);                // 
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 0.0f, 40920.0f)) < 500) {		// BP->P  
		portalID = 18;
		fromRoomID = 5;
		toRoomID = 22;
		to = FVector(-44700.0f, 0.0f, 6380.0f);
	}









	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 9000.0f, 1310.0f)) < 500) {		// P->GP
		portalID = 19;
		fromRoomID = 22;
		toRoomID = 14;
		to = FVector(-45000.0f, -36300.0f, 1310.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -36000.0f, 1310.0f)) < 500) {		// GP->P
		portalID = 19;
		fromRoomID = 14;
		toRoomID = 22;
		to = FVector(-45000.0f, 8700.0f, 1310.0f);
	}








	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 0.0f, -4040.0f)) < 500) {		// P->OP
		portalID = 20;
		fromRoomID = 22;
		toRoomID = 17;
		to = FVector(-45000.0f, 0.0f, -38640.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 0.0f, -38640.0f)) < 500) {		// OP->P
		portalID = 20;
		fromRoomID = 17;
		toRoomID = 22;
		to = FVector(-44700.0f, 0.0f, -4040.0f);
	}









	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -9000.0f, 1310.0f)) < 500) {		// P->PR
		portalID = 21;
		fromRoomID = 22;
		toRoomID = 23;
		to = FVector(-45000.0f, 36000.0f, 1310.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 36000.0f, 1310.0f)) < 500) {		// PR->P
		portalID = 21;
		fromRoomID = 23;
		toRoomID = 22;
		to = FVector(-45000.0f, -8700.0f, 1310.0f);
	}




	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 45000.0f, 6380.0f)) < 500) {		// R->BR
		portalID = 22;
		fromRoomID = 24;
		toRoomID = 7;
		to = FVector(0.0f, 44700.0f, 40920.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 45000.0f, 40920.0f)) < 500) {		// BR->R
		portalID = 22;
		fromRoomID = 7;
		toRoomID = 24;
		to = FVector(0.0f, 45300.0f, 6380.0f);
	}















	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 45000.0f, -4040.0f)) < 500) {		// R->OR
		portalID = 23;
		fromRoomID = 24;
		toRoomID = 19;
		to = FVector(0.0f, 44700.0f, -38640.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 45000.0f, -38640.0f)) < 500) {		// OR->R
		portalID = 23;
		fromRoomID = 19;
		toRoomID = 24;
		to = FVector(0.0f, 44700.0f, -4040.0f);
	}








	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 24;
	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 25;
	}






	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 0.0f, 6380.0f)) < 500) {		// Y->BY
		portalID = 26;
		fromRoomID = 26;
		toRoomID = 9;
		to = FVector(45000.0f, -300.0f, 40920.0f);
	}


	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 0.0f, 40920.0f)) < 500) {		// BY->Y
		portalID = 26;
		fromRoomID = 9;
		toRoomID = 26;
		to = FVector(45300.0f, 0.0f, 6380.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -9000.0f, 1310.0f)) < 500) {		// Y->GY
		portalID = 27;
		fromRoomID = 26;
		toRoomID = 15;
		to = FVector(45000.0f, -36300.0f, 1310.0f);
	}


	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -36000.0f, 1310.0f)) < 500) {		// GY->Y
		portalID = 27;
		fromRoomID = 15;
		toRoomID = 26;
		to = FVector(45000.0f, -8700.0f, 1310.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 0.0f, -4040.0f)) < 500) {		// Y->OY
		portalID = 28;
		fromRoomID = 26;
		toRoomID = 21;
		to = FVector(44700.0f, 0.0f, -38640.0f);
	}
	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 0.0f, -38640.0f)) < 500) {		// OY->Y
		portalID = 28;
		fromRoomID = 21;
		toRoomID = 26;
		to = FVector(44700.0f, 0.0f, -4040.0f);
	}



	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 29;
	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 30;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 31;
	}




	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// BP->BGP 
		portalID = 32;
		fromRoomID = 0;
		toRoomID = 0;
		to = FVector(0.0f, 0.0f, 0.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// BGP ->BP     
		portalID = 32;
		fromRoomID = 0;
		toRoomID = 0;
		to = FVector(0.0f, 0.0f, 0.0f);

	}





	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 9000.0f, 46310.0f)) < 500) {		// BP->BPR 
		portalID = 33;
		fromRoomID = 5;
		toRoomID = 6;
		to = FVector(-45000.0f, 36300.0f, 46310.0f);

	}
	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, 36000.0f, 46310.0f)) < 500) {		// BPR ->BP     
		portalID = 33;
		fromRoomID = 6;
		toRoomID = 5;
		to = FVector(-45000.0f, 8700.0f, 46310.0f);

	}













	if (FVector::Dist(GetActorLocation(), FVector(-9000.0f, 45000.0f, 46310.0f)) < 500) {		// BR->BPR
		portalID = 34;
		fromRoomID = 7;
		toRoomID = 6;
		to = FVector(-36300.0f, 45000.0f, 46310.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-36000.0f, 45000.0f, 46310.0f)) < 500) {		// BPR->BR
		portalID = 34;
		fromRoomID = 6;
		toRoomID = 7;
		to = FVector(-8700.0f, 45000.0f, 46310.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, 45000.0f, 46310.0f)) < 500) {		// BR->BRY
		portalID = 35;
		fromRoomID = 7;
		toRoomID = 8;
		to = FVector(36300.0f, 0.0f, 46310.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(36000.0f, 0.0f, 46310.0f)) < 500) {		// BRY->BR
		portalID = 35;
		fromRoomID = 8;
		toRoomID = 7;
		to = FVector(8700.0f, 45000.0f, 46310.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 36;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 37;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 38;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 39;
	}




	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -45000.0f, 6380.0f)) < 500) {		// GP->BGP
		portalID = 40;
		fromRoomID = 14;
		toRoomID = 3;
		to = FVector(-45000.0f, -44700.0f, 40920.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -45000.0f, 40920.0f)) < 500) {		// BGP->GP
		portalID = 40;
		fromRoomID = 3;
		toRoomID = 14;
		to = FVector(-45000.0f, -44700.0f, 6380.0f);
	}








	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -45000.0f, -4040.0f)) < 500) {		// GP->GOP
		portalID = 41;
		fromRoomID = 14;
		toRoomID = 12;
		to = FVector(-45000.0f, -44700.0f, -38640.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(-45000.0f, -45000.0f, -38640.0f)) < 500) {		// GOP->GP
		portalID = 40;
		fromRoomID = 12;
		toRoomID = 14;
		to = FVector(-45000.0f, -44700.0f, -4040.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -45000.0f, 6380.0f)) < 500) {		// GY->BGY
		portalID = 42;
		fromRoomID = 15;
		toRoomID = 4;
		to = FVector(45000.0f, -44700.0f, 40920.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -45000.0f, 40920.0f)) < 500) {		// BGY->GY
		portalID = 42;
		fromRoomID = 4;
		toRoomID = 15;
		to = FVector(45000.0f, -44700.0f, 6380.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -45000.0f, -4040.0f)) < 500) {		// GY->GOY
		portalID = 43;
		fromRoomID = 15;
		toRoomID = 4;
		to = FVector(45000.0f, -44700.0f, -38640.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -45000.0f, -38640.0f)) < 500) {		// GOY->GY
		portalID = 43;
		fromRoomID = 4;
		toRoomID = 15;
		to = FVector(45000.0f, -44700.0f, -4040.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 43;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 44;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 45;
	}







	if (FVector::Dist(GetActorLocation(), FVector(-9000.0f, 45000.0f, -43690.0f)) < 500) {		// OR -> OPR
		portalID = 46;
		fromRoomID = 19;
		toRoomID = 18;
		to = FVector(-36300.0f, 45000.0f, -43690.0f);
	}
	if (FVector::Dist(GetActorLocation(), FVector(-36000.0f, 45000.0f, -43690.0f)) < 500) {		// OPR -> OR
		portalID = 46;
		fromRoomID = 18;
		toRoomID = 19;
		to = FVector(-8700.0f, 45000.0f, -43690.0f);
	}







	if (FVector::Dist(GetActorLocation(), FVector(36000.0f, 45000.0f, -43690.0f)) < 500) {		// OR -> ORY
		portalID = 47;
		fromRoomID = 19;
		toRoomID = 20;
		to = FVector(8700.0f, 45000.0f, -43690.0f);
	}
	if (FVector::Dist(GetActorLocation(), FVector(9000.0f, 45000.0f, -43690.0f)) < 500) {		// ORY -> OR
		portalID = 47;
		fromRoomID = 20;
		toRoomID = 19;
		to = FVector(36300.0f, 45000.0f, -43690.0f);
	}




	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -9000.0f, -43690.0f)) < 500) {		// OY -> GOY
		portalID = 48;
		fromRoomID = 21;
		toRoomID = 13;
		to = FVector(45000.0f, -36300.0f, -43690.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, -36000.0f, -43690.0f)) < 500) {		// GOY -> OY
		portalID = 48;
		fromRoomID = 13;
		toRoomID = 21;
		to = FVector(45000.0f, -8700.0f, -43690.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 9000.0f, -43690.0f)) < 500) {		// OY -> ORY
		portalID = 49;
		fromRoomID = 21;
		toRoomID = 20;
		to = FVector(45000.0f, 36300.0f, -43690.0f);
	}

	if (FVector::Dist(GetActorLocation(), FVector(45000.0f, 36000.0f, -43690.0f)) < 500) {		// ORY -> OY
		portalID = 49;
		fromRoomID = 20;
		toRoomID = 21;
		to = FVector(45000.0f, 8700.0f, -43690.0f);
	}






	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 50;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 51;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// ???->??? || ???->???
		portalID = 52;
	}

	if (FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500 || FVector::Dist(GetActorLocation(), FVector(0.0f, 0.0f, 0.0f)) < 500) {		// RY->ORY || ORY->RY
		portalID = 53;
	}
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//Check if should be unlocked.
	player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (unlocked == false) {
		if (portalID != -1) {
			unlocked = true;
		}
		else {
			if (player->getEndingUnlocked(portalID)) {
				unlocked = true;
			}
		}
	}


	if (FVector3d::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < 700) {

		player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());


		player->setInteractWarning(10);

		float xDist = GetActorLocation().X - player->GetActorLocation().X;
		if (xDist < 0.0f) {
			xDist *= -1.0f;
		}
		float yDist = GetActorLocation().Y - player->GetActorLocation().Y;
		if (yDist < 0.0f) {
			yDist *= -1.0f;
		}

		if (xDist > yDist) {
			if ( player->GetActorLocation().X - GetActorLocation().X > 0.0f) {
				player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y, GetActorLocation().Z));
			}
			else {
				player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y, GetActorLocation().Z));

			}
		}
		else {
			if (xDist < yDist) {
				if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
					player->setCheckPoint(FVector(GetActorLocation().X , GetActorLocation().Y + 300.0f, GetActorLocation().Z));
				}
				else {
					player->setCheckPoint(FVector(GetActorLocation().X , GetActorLocation().Y - 300.0f, GetActorLocation().Z));

				}
			}
			else {
				if (player->GetActorLocation().X - GetActorLocation().X > 0.0f) {
					if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
						player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y + 300.0f, GetActorLocation().Z));
					}
					else {
						player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y - 300.0f, GetActorLocation().Z));

					}
				}
				else {
					if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
						player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y + 300.0f, GetActorLocation().Z));
					}
					else {
						player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y - 300.0f, GetActorLocation().Z));

					}
				}
			}
		}


		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("interact warning is "));

		if (unlocked) {
			if (player->getInteractDuration() > 0) {
				player->setInteractDuration(0.f);
				GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(to);
				player->setCheckPoint(to);
				player->setCurrentRoomID(toRoomID);
				player->setSpeed(FVector(0.f,0.f,0.f));
				player->setVsitedPortal(portalID, true);


			//	if (GEngine) {
			//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LOCATION: %f,%f,%f"), to.X, to.Y, to.Z));
				//}
			}
		}
	}




}

