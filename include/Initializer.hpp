#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP


namespace Taverner
{
    /** \brief Class that will be either created once, or inherited privately. This will allow to use RAII to initialize and close systems.
               Voila! No WTFs when encountering some strange functions!
     */
    class Initializer
    {
        public:
            //Everything we need will be initialized in Initializer's constructor,
            Initializer();
            //And deleted in destructor.
            ~Initializer();
        protected:
        private:
    };
}

#endif // INITIALIZER_HPP
