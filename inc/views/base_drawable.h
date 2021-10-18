#ifndef BASE_DRAWABLE_H
#define BASE_DRAWABLE_H

#include "../interfaces/drawable.h"
#include "../interfaces/iview.h"

class BaseDrawable: public Drawable
{
public:
	BaseDrawable() = default;
	const IView& getView() const;
	void setView(std::shared_ptr<IView> _view);

	BaseDrawable(const BaseDrawable& other);
	BaseDrawable(BaseDrawable&& other);
	BaseDrawable& operator =(const BaseDrawable& other);
	BaseDrawable& operator =(BaseDrawable&& other);
protected:
	std::shared_ptr<IView> view;
};

#endif
