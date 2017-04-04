//
//  Options_hpp
//  Snake_SFML_v1
//
//  Created by Abdulrahman on 3/28/17.
//  Copyright © 2017 Abdulrahman Tolba. All rights reserved.
//

#ifndef Options_hpp
#define Options_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"
#include "Menu.hpp"


class Options : public Menu {
public:
    // Default constructor to display the options menu to the user
    // Post-condition: Option is set at 'Novice'
	Options();
};

#endif /* Options_hpp */
