#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
: targets()
{
}
TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it)
    {
        delete it->second;
    }
    targets.clear();
}
void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
        targets.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}
void TargetGenerator::forgetTargetType(const std::string& type)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(type);
    if (it != targets.end())
    {
        delete it->second;
        targets.erase(it);
    }
}
ATarget* TargetGenerator::createTarget(const std::string& type)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(type);
    if (it != targets.end())
        return it->second->clone();
    return NULL;
}
