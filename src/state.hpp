#pragma once

namespace Flappy
{
    class State
    {
    private:
        /* data */
    public:
        State(/* args */);
        ~State();
        virtual void init() = 0;
        virtual void handle_input() = 0;
        virtual void update() = 0;
        virtual void draw(float dt) = 0;
        virtual void pause()=0;
        virtual void resume()=0;
    };

    State::State(/* args */)
    {
    }

    State::~State()
    {
    }

} // namespace Flappy
