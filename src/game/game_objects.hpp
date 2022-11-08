using GameObjects = std::vector<GameObject>;

class GameObject {
public:
    GameObject();
    
};

class Fruit : public GameObject {
public:
    Fruit();

private:
    Position pos_;
};