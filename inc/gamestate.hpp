#pragma once

namespace Cs {

    enum class GameState {
		MainMenu,
		GamePlay
	};

    extern GameState currentState;

}