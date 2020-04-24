/*************************************************************************/
/*  pool_arrays.cpp                                                      */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "gdnative/pool_arrays.h"

#include "core/array.h"

#include "core/variant.h"

#include "core/color.h"
#include "core/math/vector2.h"
#include "core/math/vector3.h"

#include <algorithm>

#ifdef __cplusplus
extern "C" {
#endif

#define memnew_placement_custom(m_placement, m_class, m_constr) _post_initialize(new (m_placement, sizeof(m_class), "") m_constr)

// byte

void GDAPI godot_packed_byte_array_new(godot_packed_byte_array *r_dest) {
	std::vector<uint8_t> *dest = (std::vector<uint8_t> *)r_dest;
	memnew_placement(dest, std::vector<uint8_t>);
}

void GDAPI godot_packed_byte_array_new_copy(godot_packed_byte_array *r_dest, const godot_packed_byte_array *p_src) {
	std::vector<uint8_t> *dest = (std::vector<uint8_t> *)r_dest;
	const std::vector<uint8_t> *src = (const std::vector<uint8_t> *)p_src;
	memnew_placement(dest, std::vector<uint8_t>(*src));
}

void GDAPI godot_packed_byte_array_new_with_array(godot_packed_byte_array *r_dest, const godot_array *p_a) {
	std::vector<uint8_t> *dest = (std::vector<uint8_t> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<uint8_t>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_byte_array_append(godot_packed_byte_array *p_self, const uint8_t p_data) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_byte_array_append_array(godot_packed_byte_array *p_self, const godot_packed_byte_array *p_array) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	std::vector<uint8_t> *array = (std::vector<uint8_t> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_byte_array_insert(godot_packed_byte_array *p_self, const godot_int p_idx, const uint8_t p_data) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, p_data));
}

void GDAPI godot_packed_byte_array_invert(godot_packed_byte_array *p_self) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_byte_array_push_back(godot_packed_byte_array *p_self, const uint8_t p_data) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_byte_array_remove(godot_packed_byte_array *p_self, const godot_int p_idx) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_byte_array_resize(godot_packed_byte_array *p_self, const godot_int p_size) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_byte_array_set(godot_packed_byte_array *p_self, const godot_int p_idx, const uint8_t p_data) {
	std::vector<uint8_t> *self = (std::vector<uint8_t> *)p_self;
	self->at(p_idx) = p_data;
}

uint8_t GDAPI godot_packed_byte_array_get(const godot_packed_byte_array *p_self, const godot_int p_idx) {
	const std::vector<uint8_t> *self = (const std::vector<uint8_t> *)p_self;
	return self->at(p_idx);
}

godot_int GDAPI godot_packed_byte_array_size(const godot_packed_byte_array *p_self) {
	const std::vector<uint8_t> *self = (const std::vector<uint8_t> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_byte_array_empty(const godot_packed_byte_array *p_self) {
	const std::vector<uint8_t> *self = (const std::vector<uint8_t> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_byte_array_destroy(godot_packed_byte_array *p_self) {
	delete ((std::vector<uint8_t> *)p_self);
}

// int

void GDAPI godot_packed_int_array_new(godot_packed_int_array *r_dest) {
	std::vector<godot_int> *dest = (std::vector<godot_int> *)r_dest;
	memnew_placement(dest, std::vector<godot_int>);
}

void GDAPI godot_packed_int_array_new_copy(godot_packed_int_array *r_dest, const godot_packed_int_array *p_src) {
	std::vector<godot_int> *dest = (std::vector<godot_int> *)r_dest;
	const std::vector<godot_int> *src = (const std::vector<godot_int> *)p_src;
	memnew_placement(dest, std::vector<godot_int>(*src));
}

void GDAPI godot_packed_int_array_new_with_array(godot_packed_int_array *r_dest, const godot_array *p_a) {
	std::vector<godot_int> *dest = (std::vector<godot_int> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<godot_int>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_int_array_append(godot_packed_int_array *p_self, const godot_int p_data) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_int_array_append_array(godot_packed_int_array *p_self, const godot_packed_int_array *p_array) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	std::vector<godot_int> *array = (std::vector<godot_int> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_int_array_insert(godot_packed_int_array *p_self, const godot_int p_idx, const godot_int p_data) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, p_data));
}

void GDAPI godot_packed_int_array_invert(godot_packed_int_array *p_self) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_int_array_push_back(godot_packed_int_array *p_self, const godot_int p_data) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_int_array_remove(godot_packed_int_array *p_self, const godot_int p_idx) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_int_array_resize(godot_packed_int_array *p_self, const godot_int p_size) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_int_array_set(godot_packed_int_array *p_self, const godot_int p_idx, const godot_int p_data) {
	std::vector<godot_int> *self = (std::vector<godot_int> *)p_self;
	self->at(p_idx) = p_data;
}

godot_int GDAPI godot_packed_int_array_get(const godot_packed_int_array *p_self, const godot_int p_idx) {
	const std::vector<godot_int> *self = (const std::vector<godot_int> *)p_self;
	return self->at(p_idx);
}

godot_int GDAPI godot_packed_int_array_size(const godot_packed_int_array *p_self) {
	const std::vector<godot_int> *self = (const std::vector<godot_int> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_int_array_empty(const godot_packed_int_array *p_self) {
	const std::vector<godot_int> *self = (const std::vector<godot_int> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_int_array_destroy(godot_packed_int_array *p_self) {
	delete ((std::vector<godot_int> *)p_self);
}

// real

void GDAPI godot_packed_real_array_new(godot_packed_real_array *r_dest) {
	std::vector<godot_real> *dest = (std::vector<godot_real> *)r_dest;
	memnew_placement(dest, std::vector<godot_real>);
}

void GDAPI godot_packed_real_array_new_copy(godot_packed_real_array *r_dest, const godot_packed_real_array *p_src) {
	std::vector<godot_real> *dest = (std::vector<godot_real> *)r_dest;
	const std::vector<godot_real> *src = (const std::vector<godot_real> *)p_src;
	memnew_placement(dest, std::vector<godot_real>(*src));
}

void GDAPI godot_packed_real_array_new_with_array(godot_packed_real_array *r_dest, const godot_array *p_a) {
	std::vector<godot_real> *dest = (std::vector<godot_real> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<godot_real>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_real_array_append(godot_packed_real_array *p_self, const godot_real p_data) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_real_array_append_array(godot_packed_real_array *p_self, const godot_packed_real_array *p_array) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	std::vector<godot_real> *array = (std::vector<godot_real> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_real_array_insert(godot_packed_real_array *p_self, const godot_int p_idx, const godot_real p_data) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, p_data));
}

void GDAPI godot_packed_real_array_invert(godot_packed_real_array *p_self) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_real_array_push_back(godot_packed_real_array *p_self, const godot_real p_data) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	self->push_back(p_data);
}

void GDAPI godot_packed_real_array_remove(godot_packed_real_array *p_self, const godot_int p_idx) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_real_array_resize(godot_packed_real_array *p_self, const godot_int p_size) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_real_array_set(godot_packed_real_array *p_self, const godot_int p_idx, const godot_real p_data) {
	std::vector<godot_real> *self = (std::vector<godot_real> *)p_self;
	self->at(p_idx) = p_data;
}

godot_real GDAPI godot_packed_real_array_get(const godot_packed_real_array *p_self, const godot_int p_idx) {
	const std::vector<godot_real> *self = (const std::vector<godot_real> *)p_self;
	return self->at(p_idx);
}

godot_int GDAPI godot_packed_real_array_size(const godot_packed_real_array *p_self) {
	const std::vector<godot_real> *self = (const std::vector<godot_real> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_real_array_empty(const godot_packed_real_array *p_self) {
	const std::vector<godot_real> *self = (const std::vector<godot_real> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_real_array_destroy(godot_packed_real_array *p_self) {
	delete ((std::vector<godot_real> *)p_self);
}

// string

void GDAPI godot_packed_string_array_new(godot_packed_string_array *r_dest) {
	std::vector<String> *dest = (std::vector<String> *)r_dest;
	memnew_placement(dest, std::vector<String>);
}

void GDAPI godot_packed_string_array_new_copy(godot_packed_string_array *r_dest, const godot_packed_string_array *p_src) {
	std::vector<String> *dest = (std::vector<String> *)r_dest;
	const std::vector<String> *src = (const std::vector<String> *)p_src;
	memnew_placement(dest, std::vector<String>(*src));
}

void GDAPI godot_packed_string_array_new_with_array(godot_packed_string_array *r_dest, const godot_array *p_a) {
	std::vector<String> *dest = (std::vector<String> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<String>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_string_array_append(godot_packed_string_array *p_self, const godot_string *p_data) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	String &s = *(String *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_string_array_append_array(godot_packed_string_array *p_self, const godot_packed_string_array *p_array) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	std::vector<String> *array = (std::vector<String> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_string_array_insert(godot_packed_string_array *p_self, const godot_int p_idx, const godot_string *p_data) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	String &s = *(String *)p_data;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, s));
}

void GDAPI godot_packed_string_array_invert(godot_packed_string_array *p_self) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_string_array_push_back(godot_packed_string_array *p_self, const godot_string *p_data) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	String &s = *(String *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_string_array_remove(godot_packed_string_array *p_self, const godot_int p_idx) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_string_array_resize(godot_packed_string_array *p_self, const godot_int p_size) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_string_array_set(godot_packed_string_array *p_self, const godot_int p_idx, const godot_string *p_data) {
	std::vector<String> *self = (std::vector<String> *)p_self;
	String &s = *(String *)p_data;
	self->at(p_idx) = s;
}

godot_string GDAPI godot_packed_string_array_get(const godot_packed_string_array *p_self, const godot_int p_idx) {
	const std::vector<String> *self = (const std::vector<String> *)p_self;
	godot_string str;
	String *s = (String *)&str;
	memnew_placement(s, String);
	*s = self->at(p_idx);
	return str;
}

godot_int GDAPI godot_packed_string_array_size(const godot_packed_string_array *p_self) {
	const std::vector<String> *self = (const std::vector<String> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_string_array_empty(const godot_packed_string_array *p_self) {
	const std::vector<String> *self = (const std::vector<String> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_string_array_destroy(godot_packed_string_array *p_self) {
	delete ((std::vector<String> *)p_self);
}

// vector2

void GDAPI godot_packed_vector2_array_new(godot_packed_vector2_array *r_dest) {
	std::vector<Vector2> *dest = (std::vector<Vector2> *)r_dest;
	memnew_placement(dest, std::vector<Vector2>);
}

void GDAPI godot_packed_vector2_array_new_copy(godot_packed_vector2_array *r_dest, const godot_packed_vector2_array *p_src) {
	std::vector<Vector2> *dest = (std::vector<Vector2> *)r_dest;
	const std::vector<Vector2> *src = (const std::vector<Vector2> *)p_src;
	memnew_placement(dest, std::vector<Vector2>(*src));
}

void GDAPI godot_packed_vector2_array_new_with_array(godot_packed_vector2_array *r_dest, const godot_array *p_a) {
	std::vector<Vector2> *dest = (std::vector<Vector2> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<Vector2>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_vector2_array_append(godot_packed_vector2_array *p_self, const godot_vector2 *p_data) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	Vector2 &s = *(Vector2 *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_vector2_array_append_array(godot_packed_vector2_array *p_self, const godot_packed_vector2_array *p_array) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	std::vector<Vector2> *array = (std::vector<Vector2> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_vector2_array_insert(godot_packed_vector2_array *p_self, const godot_int p_idx, const godot_vector2 *p_data) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	Vector2 &s = *(Vector2 *)p_data;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, s));
}

void GDAPI godot_packed_vector2_array_invert(godot_packed_vector2_array *p_self) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_vector2_array_push_back(godot_packed_vector2_array *p_self, const godot_vector2 *p_data) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	Vector2 &s = *(Vector2 *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_vector2_array_remove(godot_packed_vector2_array *p_self, const godot_int p_idx) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_vector2_array_resize(godot_packed_vector2_array *p_self, const godot_int p_size) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_vector2_array_set(godot_packed_vector2_array *p_self, const godot_int p_idx, const godot_vector2 *p_data) {
	std::vector<Vector2> *self = (std::vector<Vector2> *)p_self;
	Vector2 &s = *(Vector2 *)p_data;
	self->at(p_idx) = s;
}

godot_vector2 GDAPI godot_packed_vector2_array_get(const godot_packed_vector2_array *p_self, const godot_int p_idx) {
	const std::vector<Vector2> *self = (const std::vector<Vector2> *)p_self;
	godot_vector2 v;
	Vector2 *s = (Vector2 *)&v;
	*s = self->at(p_idx);
	return v;
}

godot_int GDAPI godot_packed_vector2_array_size(const godot_packed_vector2_array *p_self) {
	const std::vector<Vector2> *self = (const std::vector<Vector2> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_vector2_array_empty(const godot_packed_vector2_array *p_self) {
	const std::vector<Vector2> *self = (const std::vector<Vector2> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_vector2_array_destroy(godot_packed_vector2_array *p_self) {
	delete ((std::vector<Vector2> *)p_self);
}

// vector3

void GDAPI godot_packed_vector3_array_new(godot_packed_vector3_array *r_dest) {
	std::vector<Vector3> *dest = (std::vector<Vector3> *)r_dest;
	memnew_placement(dest, std::vector<Vector3>);
}

void GDAPI godot_packed_vector3_array_new_copy(godot_packed_vector3_array *r_dest, const godot_packed_vector3_array *p_src) {
	std::vector<Vector3> *dest = (std::vector<Vector3> *)r_dest;
	const std::vector<Vector3> *src = (const std::vector<Vector3> *)p_src;
	memnew_placement(dest, std::vector<Vector3>(*src));
}

void GDAPI godot_packed_vector3_array_new_with_array(godot_packed_vector3_array *r_dest, const godot_array *p_a) {
	std::vector<Vector3> *dest = (std::vector<Vector3> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<Vector3>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_vector3_array_append(godot_packed_vector3_array *p_self, const godot_vector3 *p_data) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	Vector3 &s = *(Vector3 *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_vector3_array_append_array(godot_packed_vector3_array *p_self, const godot_packed_vector3_array *p_array) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	std::vector<Vector3> *array = (std::vector<Vector3> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_vector3_array_insert(godot_packed_vector3_array *p_self, const godot_int p_idx, const godot_vector3 *p_data) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	Vector3 &s = *(Vector3 *)p_data;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, s));
}

void GDAPI godot_packed_vector3_array_invert(godot_packed_vector3_array *p_self) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_vector3_array_push_back(godot_packed_vector3_array *p_self, const godot_vector3 *p_data) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	Vector3 &s = *(Vector3 *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_vector3_array_remove(godot_packed_vector3_array *p_self, const godot_int p_idx) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_vector3_array_resize(godot_packed_vector3_array *p_self, const godot_int p_size) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_vector3_array_set(godot_packed_vector3_array *p_self, const godot_int p_idx, const godot_vector3 *p_data) {
	std::vector<Vector3> *self = (std::vector<Vector3> *)p_self;
	Vector3 &s = *(Vector3 *)p_data;
	self->at(p_idx) = s;
}

godot_vector3 GDAPI godot_packed_vector3_array_get(const godot_packed_vector3_array *p_self, const godot_int p_idx) {
	const std::vector<Vector3> *self = (const std::vector<Vector3> *)p_self;
	godot_vector3 v;
	Vector3 *s = (Vector3 *)&v;
	*s = self->at(p_idx);
	return v;
}

godot_int GDAPI godot_packed_vector3_array_size(const godot_packed_vector3_array *p_self) {
	const std::vector<Vector3> *self = (const std::vector<Vector3> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_vector3_array_empty(const godot_packed_vector3_array *p_self) {
	const std::vector<Vector3> *self = (const std::vector<Vector3> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_vector3_array_destroy(godot_packed_vector3_array *p_self) {
	delete ((std::vector<Vector3> *)p_self);
}

// color

void GDAPI godot_packed_color_array_new(godot_packed_color_array *r_dest) {
	std::vector<Color> *dest = (std::vector<Color> *)r_dest;
	memnew_placement(dest, std::vector<Color>);
}

void GDAPI godot_packed_color_array_new_copy(godot_packed_color_array *r_dest, const godot_packed_color_array *p_src) {
	std::vector<Color> *dest = (std::vector<Color> *)r_dest;
	const std::vector<Color> *src = (const std::vector<Color> *)p_src;
	memnew_placement(dest, std::vector<Color>(*src));
}

void GDAPI godot_packed_color_array_new_with_array(godot_packed_color_array *r_dest, const godot_array *p_a) {
	std::vector<Color> *dest = (std::vector<Color> *)r_dest;
	Array *a = (Array *)p_a;
	memnew_placement(dest, std::vector<Color>);

	dest->resize(a->size());
	for (int i = 0; i < a->size(); i++) {
		dest->at(i) = (*a)[i];
	}
}

void GDAPI godot_packed_color_array_append(godot_packed_color_array *p_self, const godot_color *p_data) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	Color &s = *(Color *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_color_array_append_array(godot_packed_color_array *p_self, const godot_packed_color_array *p_array) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	std::vector<Color> *array = (std::vector<Color> *)p_array;
	self->insert(self->end(), array->begin(), array->end());
}

godot_error GDAPI godot_packed_color_array_insert(godot_packed_color_array *p_self, const godot_int p_idx, const godot_color *p_data) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	Color &s = *(Color *)p_data;
	return (godot_error)std::distance(self->begin(), self->insert(self->begin() + p_idx, s));
}

void GDAPI godot_packed_color_array_invert(godot_packed_color_array *p_self) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	std::reverse(self->begin(), self->end());
}

void GDAPI godot_packed_color_array_push_back(godot_packed_color_array *p_self, const godot_color *p_data) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	Color &s = *(Color *)p_data;
	self->push_back(s);
}

void GDAPI godot_packed_color_array_remove(godot_packed_color_array *p_self, const godot_int p_idx) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	self->erase(self->begin() + p_idx);
}

void GDAPI godot_packed_color_array_resize(godot_packed_color_array *p_self, const godot_int p_size) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	self->resize(p_size);
}

void GDAPI godot_packed_color_array_set(godot_packed_color_array *p_self, const godot_int p_idx, const godot_color *p_data) {
	std::vector<Color> *self = (std::vector<Color> *)p_self;
	Color &s = *(Color *)p_data;
	self->at(p_idx) = s;
}

godot_color GDAPI godot_packed_color_array_get(const godot_packed_color_array *p_self, const godot_int p_idx) {
	const std::vector<Color> *self = (const std::vector<Color> *)p_self;
	godot_color v;
	Color *s = (Color *)&v;
	*s = self->at(p_idx);
	return v;
}

godot_int GDAPI godot_packed_color_array_size(const godot_packed_color_array *p_self) {
	const std::vector<Color> *self = (const std::vector<Color> *)p_self;
	return self->size();
}

godot_bool GDAPI godot_packed_color_array_empty(const godot_packed_color_array *p_self) {
	const std::vector<Color> *self = (const std::vector<Color> *)p_self;
	return self->empty();
}

void GDAPI godot_packed_color_array_destroy(godot_packed_color_array *p_self) {
	delete ((std::vector<Color> *)p_self);
}

#ifdef __cplusplus
}
#endif
