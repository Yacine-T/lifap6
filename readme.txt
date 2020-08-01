Students : XXXX XXXXXXX (student who collaborate with me) - TAZDAIT Yacine
Teacher/Professor : XXXXX XXXX

I - English version

1) Compile and run the project :

To compile and execute this project, please follow this instructions :
	
	1 - First, go inside this folder "~/Documents/projet/projetlifap6" and type this command "premake4 gmake". It will create a makefile.
	2 - Secondly, type "make" to compile the project. It will turn the source code into binary code and create an executable file. 
	3 - Then, go inside this folder "~/Documents/projet/projetlifap6/bin" where you can find the executable created.
	4 - Finally, type this command "./<name_of_the_executable>" to execute the code.
	    If it still doesn't work, you can compile and execute the code with the tools provided by netbeans.
	
2) Role in the project :

	Raoufdine was in charge of the project analysis. He created an UML diagramm and explained the strategy we used 
	(type of data structures etc ...).
	To develop this project, we worked in pair programming. One of us was coding and the other was checking and 
	correcting the syntax error. He was also giving this instructions. Then we swap roles.
	
3) Reached Goals :

	Improvement of the given code and implementation of the scrabble.
	Implementation of the GADDAG to know if a word played exist.
	Implementation of an AI to simulate players in the scrabble.
	Implementation of the existing moves to determine which is the best.
	Implementation of data structures to have a programm working in constant time complexity.
	Creation of the bonus (joker).
	
4) Bugs and difficulties :
	
	Review of data structure. We change to a static array to improve the time complexity of the programm (we used a vector before).
	There was an extra parameter in the function "canPlaceLetterAt" (AIScrabble class). So we took it off and the programm worked.
	

II - Version Francaise



1) Compilation :

	1 - Pour compiler ce projet, vous devez vous rendre dans le dossier "~/Documents/projet/projetlifap6" 
	2 - Tapez les commandes suivantes : 
		2.1 - premake4 gmake
		2.2 - puis make
	3 - Allez dans le dossier "~/Documents/projet/projetlifap6/bin" pour trouver un éxécutable. 
	4 - Ainsi, vous devez taper : 
		3 - ./<nom de l'éxécutable>
	
	Dans le cas où vous rencontrez un problème, vous pouvez utiliser Netbeans et compiler puis éxécuter avec les outils proposés par l'ide.

2) Rôle dans le projet :

	On analysait les problèmes posés et on déterminait une stratégie (type de structure de données à utiliser etc ...).
	Pour ce qui est du développement, nous avons travaillé en pair programming. L'un programmait tandis que l'autre donnait 
	les instructions issue de la phase d'analyse. Il se chargeait également de repérer les éventuelles erreurs de syntaxe et de frappe.

3) Objectifs atteints :

	Lister les coups compatibles en évaluant lequel sera le meilleur.
	Utiliser des strcutures de données permettant d'avoir une compléxité en temps constant.
	Implémentation d'un Joker.

4) Bugs et difficultés :

	Révision de la structure choisie. Nous avons changé notre vecteur par un tableau statique.
	Un paramètre en trop faisait planter notre programme dans la classe "AIScrabble", plus précisement dans la méthode "canPlaceLetterAt".
	Nous avons dû le retirer et le programme fonctionnait à nouveau.
