#include <iostream>
#include <memory>

class CContext;

class IState
{
public:
    virtual ~IState() {}
    virtual void Insert(std::shared_ptr<CContext> context) = 0;
    virtual void Eject(std::shared_ptr<CContext> context) = 0;
    virtual void Select(std::shared_ptr<CContext> context) = 0;
    virtual void Play(std::shared_ptr<CContext> context) = 0;
    virtual void Extract(std::shared_ptr<CContext> context) = 0;
    virtual std::string StateName() const = 0;
};

class CContext : public std::enable_shared_from_this<CContext>
{
public:
    CContext();
    void SetState(std::shared_ptr<IState> state) { state_ = state; }

    void Insert() { state_->Insert(shared_from_this()); }
    void Eject() { state_->Eject(shared_from_this()); }
    void Select() { state_->Select(shared_from_this()); }
    void Play() { state_->Play(shared_from_this()); }
    void Extract() { state_->Extract(shared_from_this()); }
    std::string StateName() const { return state_->StateName(); }

private:
    std::shared_ptr<IState> state_;
};

class NoCoinState : public IState
{
public:
    void Insert(std::shared_ptr<CContext> context) override;
    void Eject(std::shared_ptr<CContext> context) override;
    void Select(std::shared_ptr<CContext> context) override;
    void Play(std::shared_ptr<CContext> context) override;
    void Extract(std::shared_ptr<CContext> context) override;
    std::string StateName() const override { return "No coin"; }
};

class HasCoinState : public IState
{
public:
    void Insert(std::shared_ptr<CContext> context) override;
    void Eject(std::shared_ptr<CContext> context) override;
    void Select(std::shared_ptr<CContext> context) override;
    void Play(std::shared_ptr<CContext> context) override;
    void Extract(std::shared_ptr<CContext> context) override;
    std::string StateName() const override { return "Has coin"; }
};

class ItemSelectedState : public IState
{
public:
    void Insert(std::shared_ptr<CContext> context) override;
    void Eject(std::shared_ptr<CContext> context) override;
    void Select(std::shared_ptr<CContext> context) override;
    void Play(std::shared_ptr<CContext> context) override;
    void Extract(std::shared_ptr<CContext> context) override;
    std::string StateName() const override { return "Item selected"; }
};

class SoldState : public IState
{
public:
    void Insert(std::shared_ptr<CContext> context) override;
    void Eject(std::shared_ptr<CContext> context) override;
    void Select(std::shared_ptr<CContext> context) override;
    void Play(std::shared_ptr<CContext> context) override;
    void Extract(std::shared_ptr<CContext> context) override;
    std::string StateName() const override { return "Sold"; }
};

void NoCoinState::Insert(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<HasCoinState>());
}

void NoCoinState::Eject(std::shared_ptr<CContext> context)
{
    std::cout << "No coin" << std::endl;
}

void NoCoinState::Select(std::shared_ptr<CContext> context)
{
    std::cout << "No coin" << std::endl;
}

void NoCoinState::Play(std::shared_ptr<CContext> context)
{
    std::cout << "No coin" << std::endl;
}

void NoCoinState::Extract(std::shared_ptr<CContext> context)
{
    std::cout << "No coin" << std::endl;
}

void HasCoinState::Insert(std::shared_ptr<CContext> context)
{
    std::cout << "Has coin" << std::endl;
}

void HasCoinState::Eject(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<NoCoinState>());
}

void HasCoinState::Select(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<ItemSelectedState>());
}

void HasCoinState::Play(std::shared_ptr<CContext> context)
{
    std::cout << "No selection" << std::endl;
}

void HasCoinState::Extract(std::shared_ptr<CContext> context)
{
    std::cout << "No selection" << std::endl;
}

void ItemSelectedState::Insert(std::shared_ptr<CContext> context)
{
    std::cout << "Has coin" << std::endl;
}

void ItemSelectedState::Eject(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<NoCoinState>());
}

void ItemSelectedState::Select(std::shared_ptr<CContext> context)
{
    std::cout << "Has selection" << std::endl;
}

void ItemSelectedState::Play(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<SoldState>());
}

void ItemSelectedState::Extract(std::shared_ptr<CContext> context)
{
    std::cout << "No Play" << std::endl;
}

void SoldState::Insert(std::shared_ptr<CContext> context)
{
    std::cout << "Sold" << std::endl;
}

void SoldState::Eject(std::shared_ptr<CContext> context)
{
    std::cout << "Sold" << std::endl;
}

void SoldState::Select(std::shared_ptr<CContext> context)
{
    std::cout << "Sold" << std::endl;
}

void SoldState::Play(std::shared_ptr<CContext> context)
{
    std::cout << "Sold" << std::endl;
}

void SoldState::Extract(std::shared_ptr<CContext> context)
{
    context->SetState(std::make_shared<NoCoinState>());
}

CContext::CContext()
    : state_(std::make_shared<NoCoinState>())
{
}

int main()
{
    auto context = std::make_shared<CContext>();
    std::cout << context->StateName() << std::endl;

    context->Insert();
    std::cout << context->StateName() << std::endl;

    context->Select();
    std::cout << context->StateName() << std::endl;

    context->Play();
    std::cout << context->StateName() << std::endl;

    context->Extract();
    std::cout << context->StateName() << std::endl;

    context->Insert();
    std::cout << context->StateName() << std::endl;

    return 0;
}