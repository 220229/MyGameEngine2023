#pragma once
class SphereCollider
{
private:
    float radius_;    //”¼Œa
public:
    /// <summary>
    /// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
    /// </summary>
    /// <param name="_r">‹…‘Ì‚Ì”¼Œa</param>
    SphereCollider(float _r);



    /// <summary>
    /// ‹…‘Ì‚Ì”¼Œa‚ÌŽæ“¾
    /// </summary>
    /// <returns>‹…‘Ì‚Ì”É”¼Œa</returns>
    float GetRadius() { return radius_; }
};

