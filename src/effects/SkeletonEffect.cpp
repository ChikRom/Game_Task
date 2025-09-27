#include "SkeletonEffect.h"
#include "Character.h"


Damage SkeletonEffect::TotalDamage(Damage baseDamage, const Character* attacker, const Character* target, int turnNumber) const
{
    return baseDamage;
}


// Skeleton effect, where he takes double damage 
// when hit with a crushing weapon.
Damage SkeletonEffect::TotalDefense(Damage incomingDamage, const Character* defender, const Character* attacker, int turnNumber) const
{
    if (attacker->getWeapon()->type == DamageType::Crushing)
    {
        return incomingDamage * 2;
    }
    return incomingDamage;
}
