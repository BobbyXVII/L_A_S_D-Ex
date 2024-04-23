
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> &Container){
    bool status = true;
    Container.Traverse([this, &status](const Data &Element){
        //result &= fa AND tra tutti gli inserimenti
        status &= Insert(std::move(Element));
    });
    return status;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> &&Container) {
    bool status = true;
    Container.Map([this,&status](Data &Element){
        status &= Insert(std::move(Element));
    });
    return status;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> &Container) {
    bool status = true;
    Container.Traverse([this,&status](const Data &Element){
        status &= Remove(Element);
    });
    return status;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &Container){
    bool status = false; //diventa true se almeno un elemento viene inserito
    Container.Traverse([this,&status](const Data &Element){
        //operazione di OR
        status |= Insert(Element);
    });
    return status;
}

template<typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&Container){
    bool status = false; //diventa true se almeno un elemento viene inserito
    Container.Map([this,&status](Data &Element){
        //operazione di OR
        status |= Insert(std::move(Element));
    });
    return status;
}

template<typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> &Container){
    bool status = false;
    Container.Traverse[this,&status](const Data &Element) {
        status |= Remove(Element);
    });
    return status;
}


/* ************************************************************************** */

}
