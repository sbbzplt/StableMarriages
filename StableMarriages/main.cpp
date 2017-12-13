#include "classes.h"

int main() {

	Man Ali;
	Man Veli; 
	Man Ahmet;
	Man Mehmet;

	Woman Ayse;
	Woman Fatma;
	Woman Zeynep;
	Woman Kadriye;

	bool isAllEngaged = false;
	int population = 3;

	std::vector<Man>::iterator itm;
	std::vector<Woman>::iterator itw;

	Ali.setName("Ali");
	Veli.setName("Veli");
	Ahmet.setName("Ahmet");
	Mehmet.setName("Mehmet");

	Ayse.setName("Ayse");
	Fatma.setName("Fatma");
	Zeynep.setName("Zeynep");
	Kadriye.setName("Kadriye");

	Ali.setPrefList(Ayse);
	Ali.setPrefList(Zeynep);
	Ali.setPrefList(Kadriye);
	Ali.setPrefList(Fatma);
	std::vector<Woman> womanList = Ali.getPrefList();

	Veli.setPrefList(Zeynep);
	Veli.setPrefList(Fatma);
	Veli.setPrefList(Kadriye);
	Veli.setPrefList(Ayse);

	Ahmet.setPrefList(Kadriye);
	Ahmet.setPrefList(Ayse);
	Ahmet.setPrefList(Zeynep);
	Ahmet.setPrefList(Fatma);

	Mehmet.setPrefList(Ayse);
	Mehmet.setPrefList(Kadriye);
	Mehmet.setPrefList(Zeynep);
	Mehmet.setPrefList(Fatma);

	Ayse.setPrefList(Ahmet);
	Ayse.setPrefList(Veli);
	Ayse.setPrefList(Ali);
	Ayse.setPrefList(Mehmet);
	std::vector<Man> manList = Ayse.getPrefList();

	Fatma.setPrefList(Veli);
	Fatma.setPrefList(Mehmet);
	Fatma.setPrefList(Ahmet);
	Fatma.setPrefList(Ali);

	Zeynep.setPrefList(Ahmet);
	Zeynep.setPrefList(Mehmet);
	Zeynep.setPrefList(Ali);
	Zeynep.setPrefList(Veli);
	
	Kadriye.setPrefList(Ali);
	Kadriye.setPrefList(Veli);
	Kadriye.setPrefList(Mehmet);
	Kadriye.setPrefList(Ahmet);

	while (!isAllEngaged)
	{
		// Every morning, women in the village left a message on their the (next-)best choices.
		for (itw = womanList.begin(); itw != womanList.end(); ++itw)
		{
			Woman woman = *itw;
			bool st = woman.getStatus();
			std::cout << woman.getName() << " " << st << std::endl;
			if (!st)
			{
				size_t round = woman.getRound();
				std::vector<Man> prefList = woman.getPrefList();
				Man nextOnTheList = prefList.at(round);
				nextOnTheList.setMessageBox(woman);
				++round;
				woman.setRound(round);
			}
		}

		// Every afternoon men check their message box and reply according to their preference list.
		for (itm = manList.begin(); itm != manList.end(); ++itm)
		{
			Man man = *itm;
			std::vector<Woman> messageBox = man.getMessageBox();
			if (messageBox.size() != 0)
			{
				std::vector<Woman> prefList = man.getPrefList();
				bool st = man.getStatus();
				

				if (!st)
				{
					// Kendine teklif getiren kizlara bakacak. Listede kendi nisanlisindan daha ustte biri varsa nisan atip yeni adayla nisanlanacak. 
				}
				else
				{
					// Kendine teklif getiren kizlara bakacak. Listede en ust siradaki adayla nisanlanacak. 
					for (itw = messageBox.begin(); itw != messageBox.end(); ++itw)
					{
						Woman woman = *itw;
						int pos1 = std::find(messageBox.begin(), messageBox.end(), woman) - messageBox.begin();
					}

					man.setStatus(true);
				}
			}
		}


		// Checking marital status of the village at the end of the day.
		int numOfCouples = 0;
		for (itm = manList.begin(); itm != manList.end(); ++itm) 
		{
			Man man = *itm;
			bool st = man.getStatus();
			std::cout << man.getName() << " " << st << std::endl;
			if (st)
			{
				++numOfCouples;
			}
		}
		if (numOfCouples == population)
		{
			isAllEngaged = true;
		}

		std::cout <<  numOfCouples << std::endl;
	}


	//std::cout << Ali.getName();
	//std::cout << Veli.getName();
	//std::cout << Hasan.getName();
	//std::cout << Ayse.getName();
	//std::cout << Fatma.getName();
	//std::cout << Hayriye.getName();


	return 0;
}