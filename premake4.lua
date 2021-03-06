solution "scrabble"
  configurations {"debug", "release"}

  configuration {"debug"}
    defines {"DEBUG"}
    if _PREMAKE_VERSION >="5.0" then
      symbols "On"
		else
			flags { "Symbols" }
		end


  configuration {"release"}
		if _PREMAKE_VERSION >="5.0" then
			optimize "speed"
		else
			flags { "OptimizeSpeed" }
		end

  configuration {"linux"}
		buildoptions { "-mtune=native -march=native" }
		buildoptions { "-std=c++11" }
		buildoptions { "-pipe" }

  configuration {"macosx"}
		buildoptions { "-std=c++11" }

  configuration {"linux", "debug"}
    buildoptions {"-g"}
    linkoptions {"-g"}

-- Ajoutez ici les fichiers supplémentaires que vous créez qui ne contiennent
-- pas de main.

common_files = {
  "src/board.hpp", "src/board.cpp",
  "src/spot.hpp", "src/spot.cpp",
  "src/bonus.hpp", "src/bonus.cpp",
  "src/AIScrabble.hpp", "src/AIScrabble.cpp",
  "src/Gaddag.hpp", "src/Gaddag.cpp",
  "src/GaddagNode.hpp", "src/GaddagNode.cpp",
  "src/KicksInformation.hpp", "src/KicksInformation.cpp",
  "src/LetterBag.hpp", "src/LetterBag.cpp",
  "src/LetterOfPlayer.hpp", "src/LetterOfPlayer.cpp",
  "src/LetterPointTable.hpp", "src/LetterPointTable.cpp",
  "src/Player.hpp", "src/Player.cpp",
  "src/Vec2i.hpp",
}

-- Pour chaque exécutable que vous souhaitez générer, ajoutez un nouveau projet
-- comme ci-dessous en mentionnant les fichiers supplémentaires nécessaires qui
-- ne sont pas dans la liste common_files, en particulier celui contenant le
-- main.

project "test_board"
  language "c++"
  kind "ConsoleApp"
  targetdir "bin"
  files ( common_files )
  files {"src/main.cpp"}
