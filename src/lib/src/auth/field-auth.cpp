#include "auth/field-auth.h"
#include <utility>


FieldAuth::FieldAuth(QString type, QList<AuthField*> fields)
	: Auth(std::move(type)), m_fields(std::move(fields))
{}


QList<AuthField*> FieldAuth::fields() const
{
	return m_fields;
}
