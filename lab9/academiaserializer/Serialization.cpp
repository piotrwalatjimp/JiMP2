//
// Created by walapiot on 08.05.18.
//

#include <functional>

#include "Serialization.h"


namespace academia
{

    std::string TypeToString(const Room::Type &typ)
    {
        switch(typ)
        {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return  "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }

    }

    Room::Room (int id, std::string number, Room::Type typ) : id_{id},number_{number},typ_{typ} {}

    void Room::Serialize (Serializer *serializer) const
    {
        serializer -> Header("room");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",number_);
        serializer ->StringField("type",TypeToString(typ_));
        serializer -> Footer("room");

    }
    void Room::Serialize (Serializer *serializer)
    {
        serializer -> Header("room");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",number_);
        serializer ->StringField("type",TypeToString(typ_));
        serializer -> Footer("room");

    }

    Serializer::Serializer (std::ostream *out) {
        out_ = out;

    }

    Building::Building (int id, std::string name, const std::vector<std::reference_wrapper<const academia::Serializable>> &rooms) :id_{id},name_{name},rooms_{rooms} {}

    void Building::Serialize(Serializer *serializer) const
    {
        serializer -> Header("building");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",name_);
        serializer -> ArrayField("rooms",rooms_);
        serializer -> Footer("building");
    }
    void Building::Serialize(Serializer *serializer)
    {
        serializer -> Header("building");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",name_);
        serializer -> ArrayField("rooms",rooms_);
        serializer -> Footer("building");
    }

    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        *(out_)<<"<"<<field_name<<">";
        for(auto v: value)
        {
            SerializableField(field_name,v.get());
        }

        *(out_)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *(out_)<<"<"<<object_name<<">";

    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *(out_)<<"<\\"<<object_name<<">";
    }

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": "<<value;

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": "<<value;

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        isFirst();
        *(out_)<<"\""<<field_name<<"\": \"";
        if (value)
            *out_<<"true";
        else
            *out_<<"false";
        *(out_)<<"\"";


    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value)
    {
        isFirst();
        *out_<<"\""<<field_name<<"\": \"";
        value.Serialize(this);

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        isFirst();
        *(out_)<<"\""<<field_name<<"\": [";
        for(int i = 0; i<value.size();i++)
        {
            first_ = true;
            if(i==0)
            {

                value[0].get().Serialize(this);
            }
            else {
                *out_<<", ";
                value[i].get().Serialize(this);
            }
        }

        *(out_)<<"]";

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";

    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

    void JsonSerializer::isFirst()
    {
        if(first_)
        {
            first_= false;
        } else
        {
            *out_<<", ";
        }
    }
}