#include "Autonomous.h"
#include "ChevalDeFrise.h"
#include "Portcullis.h"
#include "SallyPort.h"
#include "Drawbridge.h"
#include "LowBar.h"

Autonomous::Autonomous(int defenseNum)
{
	//AddSequential(new RobotDrive());
		switch(defenseNum){
				case CHEVAL_DE_FRISE: // Cheval de Frise
					AddSequential(new ChevalDeFrise());
					break;

				case PORTCULLIS : // Portcullis
					AddSequential(new Portcullis());
					break;

				case SALLY_PORT : // Sally Port
					AddSequential(new SallyPort());
					break;

				case DRAWBRIDGE : // Drawbridge
					AddSequential(new Drawbridge());
					break;

				case LOW_BAR : // Other
					AddSequential(new LowBar());
					break;

		}
}
