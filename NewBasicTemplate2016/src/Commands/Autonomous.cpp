#include "Autonomous.h"

Autonomous::Autonomous(int defenseNum)
{
	//AddSequential(new RobotDrive());
		switch(defenseNum){
				case "CHEVALDEFRISE" : // Cheval de Frise
					AddSequential(new ChevalDeFrise());
					break;

				case "PORTCULLIS" : // Portcullis
					AddSequential(new Portcullis());
					break;

				case "SALLYPORT" : // Sally Port
					AddSequential(new SallyPort());
					break;

				case "DRAWBRIDGE" : // Drawbridge
					AddSequential(new Drawbridge());
					break;

				case "LOWBAR" : // Other
					AddSequential(new AutonomousDrive());
					break;

				default: //Invalid Values
					break;
		}
}
