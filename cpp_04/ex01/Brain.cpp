#include "Brain.hpp"
// #include <random>
Brain::Brain(void)
{
        ideas[0] = "I love to run and play in the fields.";
        ideas[1] = "My fur is soft and fluffy.";
        ideas[2] = "I enjoy exploring new environments.";
        ideas[3] = "My favorite pastime is napping in the sun.";
        // ideas[4] = "I communicate with others through various sounds.";
        // ideas[5] = "I have sharp claws for climbing trees.";
        // ideas[6] = "My sense of smell helps me find food.";
        // ideas[7] = "I enjoy swimming in cool streams.";
        // ideas[8] = "I am always alert to potential dangers.";
        // ideas[9] = "My favorite food is fresh fish.";
        // ideas[10] = "I have a keen sense of hearing.";
        // ideas[11] = "I am an excellent hunter.";
        // ideas[12] = "My fur changes color to blend with my surroundings.";
        // ideas[13] = "I like to socialize with other animals.";
        // ideas[14] = "I am an expert at finding hidden water sources.";
        // ideas[15] = "I can jump high to evade predators.";
        // ideas[16] = "My long tail helps me maintain balance.";
        // ideas[17] = "I am fast and agile.";
        // ideas[18] = "I mark my territory with scent markings.";
        // ideas[19] = "I have sharp teeth for tearing meat.";
        // ideas[20] = "I am known for my endurance in long-distance running.";
        // ideas[21] = "My keen eyesight helps me spot prey from afar.";
        // ideas[22] = "I rely on camouflage to blend in with my surroundings.";
        // ideas[23] = "I am capable of flying long distances without rest.";
        // ideas[24] = "My powerful wings allow me to soar high in the sky.";
        // ideas[25] = "I have a strong sense of community within my flock.";
        // ideas[26] = "My beak is specialized for cracking open nuts and seeds.";
        // ideas[27] = "I am known for my distinctive song that varies between individuals.";
        // ideas[28] = "I build intricate nests to protect my eggs and chicks.";
        // ideas[29] = "My webbed feet make me an excellent swimmer.";
        // ideas[30] = "I communicate through complex dances and gestures.";
        // ideas[31] = "I rely on echolocation to navigate in the dark.";
        // ideas[32] = "I have a thick fur coat to keep me warm in the winter.";
        // ideas[33] = "I am capable of hibernating for months at a time.";
        // ideas[34] = "I use my sharp talons to catch and kill prey.";
        // ideas[35] = "I have a long, prehensile tail that I use for balance.";
        // ideas[36] = "I have a strong maternal instinct, fiercely protecting my young.";
        // ideas[37] = "I am known for my playful antics and curiosity.";
        // ideas[38] = "My large tusks are used for digging up roots and defending against predators.";
        // ideas[39] = "I am a master of camouflage, blending in with my surroundings.";
        // ideas[40] = "I rely on my keen sense of smell to locate food.";
        // ideas[41] = "I have specialized adaptations for climbing trees.";
        // ideas[42] = "I am capable of regenerating lost limbs.";
        // ideas[43] = "I have a long, flexible tongue for reaching nectar deep inside flowers.";
        // ideas[44] = "I communicate through a series of clicks and whistles.";
        // ideas[45] = "I have a thick, scaly hide that protects me from predators.";
        // ideas[46] = "I am known for my long, graceful neck.";
        // ideas[47] = "I use my sharp beak to crack open shells and extract the meat inside.";
        // ideas[48] = "I rely on my powerful sense of smell to track down prey.";
        // ideas[49] = "I have specialized adaptations for living in extreme temperatures.";
        // ideas[50] = "I communicate through a variety of vocalizations, from songs to grunts.";
        // ideas[51] = "I have a thick layer of blubber to insulate me from the cold.";
        // ideas[52] = "I am capable of running at high speeds for long distances.";
        // ideas[53] = "I rely on my powerful jaws to crush bones and tear flesh.";
        // ideas[54] = "I have specialized adaptations for living in dense forests.";
        // ideas[55] = "I am known for my distinctive black and white markings.";
        // ideas[56] = "I communicate through a complex system of body language and vocalizations.";
        // ideas[57] = "I am capable of diving to great depths in search of food.";
        // ideas[58] = "I have a highly developed sense of smell, which helps me navigate and find food.";
        // ideas[59] = "I am known for my intelligence and problem-solving abilities.";
        // ideas[60] = "I rely on my powerful hind legs to leap great distances.";
        // ideas[61] = "I have specialized adaptations for living in arid deserts.";
        // ideas[62] = "I communicate through a series of barks, yips, and howls.";
        // ideas[63] = "I am capable of changing color to blend in with my environment.";
        // ideas[64] = "I have a thick, muscular tail that I use for balance and communication.";
        // ideas[65] = "I rely on my acute sense of hearing to detect prey.";
        // ideas[66] = "I am known for my powerful, crushing bite.";
        // ideas[67] = "I communicate through a variety of vocalizations, including chirps and trills.";
        // ideas[68] = "I have specialized adaptations for living in cold, icy waters.";
        // ideas[69] = "I rely on my keen sense of smell to locate mates and detect danger.";
        // ideas[70] = "I am known for my ability to jump great heights and distances.";
        // ideas[71] = "I communicate through a series of grunts, growls, and roars.";
        // ideas[72] = "I have specialized adaptations for living in hot, arid climates.";
        // ideas[73] = "I am capable of climbing steep cliffs with ease.";
        // ideas[74] = "I rely on my keen eyesight to spot prey from a distance.";
        // ideas[75] = "I am known for my distinctive, colorful plumage.";
        // ideas[76] = "I communicate through a series of whistles and clicks.";
        // ideas[77] = "I have specialized adaptations for living in dense jungles.";
        // ideas[78] = "I rely on my powerful sense of smell to track down prey.";
        // ideas[79] = "I am known for my ability to run at high speeds for long distances.";
        // ideas[80] = "I communicate through a variety of vocalizations, including songs and calls.";
        // ideas[81] = "I have specialized adaptations for living in harsh, desert environments.";
        // ideas[82] = "I rely on my powerful wings to soar effortlessly through the sky.";
        // ideas[83] = "I am known for my distinctive, loud call that can be heard for miles.";
        // ideas[84] = "I have specialized adaptations for living in icy, polar regions.";
        // ideas[85] = "I communicate through a series of grunts, squeals, and clicks.";
        // ideas[86] = "I rely on my strong sense of smell to locate mates and detect danger.";
        // ideas[87] = "I am known for my ability to camouflage myself in my surroundings.";
        // ideas[88] = "I have specialized adaptations for living in dense, tropical rainforests.";
        // ideas[89] = "I communicate through a series of complex vocalizations and body movements.";
        // ideas[90] = "I rely on my powerful sense of smell to track down prey.";
        // ideas[91] = "I am known for my ability to mimic the calls of other animals.";
        // ideas[92] = "I have specialized adaptations for living in cold, snowy climates.";
        // ideas[93] = "I rely on my sharp claws and powerful jaws to catch and kill prey.";
        // ideas[94] = "I am known for my distinctive, striped coat pattern.";
        // ideas[95] = "I communicate through a series of chirps, whistles, and trills.";
        // ideas[96] = "I have specialized adaptations for living in fast-flowing rivers.";
        // ideas[97] = "I rely on my keen sense of smell to locate mates and detect danger.";
        // ideas[98] = "I am known for my ability to navigate long distances using the stars.";
        // ideas[99] = "I have specialized adaptations for living in dense, underwater kelp forests.";
}

Brain & Brain::operator=(Brain const &r_obj)
{
    if(this != &r_obj)
    {
        for (int i = 0; i < 5; ++i) {
                ideas[i] = r_obj.getIdea();
        }
    }
    return (*this);
}

std::string Brain::getIdea(void) const
{
    std::srand(std::time(NULL));

    // Generate a random number between 0 and 99
    int randomNumber = std::rand() % 5;
    return (ideas[randomNumber]);
}

// std::string Brain::getFirstIdea(void) const
// {
//     return ideas[0];
// }

Brain::~Brain(void){}

Brain::Brain(Brain const &r_obj)
{
    if(this != &r_obj)
    {
        for (int i = 0; i < 5; ++i) {
                ideas[i] = r_obj.ideas[i];
        }
    }
}   