#ifndef TARGET_GENERATOR_HPP
#define TARGET_GENERATOR_HPP

#include <map>

class ATarget;

class TargetGenerator
{
private:
    std::map<std::string, ATarget*> targets;
    TargetGenerator(const TargetGenerator& rhs);
    const TargetGenerator& operator=(const TargetGenerator& rhs);
    
public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget* target);
    void forgetTargetType(const std::string& type);
    ATarget* createTarget(const std::string& type);
};


#endif
