#include "../../inc/views/base_drawable.h"

void BaseDrawable::setView(std::shared_ptr<IView> _view)
{
	this->view = _view;
}

const IView& BaseDrawable::getView() const
{
	return *this->view.get();
}

BaseDrawable::BaseDrawable(const BaseDrawable& other): view{other.view}
{}

BaseDrawable::BaseDrawable(BaseDrawable&& other): view{other.view}
{}

BaseDrawable& BaseDrawable::operator =(const BaseDrawable& other)
{
	if (&other == this)
		return *this;

	this->view = other.view;
	return *this;
}

BaseDrawable& BaseDrawable::operator =(BaseDrawable&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->view, other.view);
	return *this;
}

