#include "../inc/field.h"
#include "../inc/actions/game_observer.h"

Field::Field(size_t width, size_t height)
{
	if (width <= 0 || height <= 0) 
		throw std::runtime_error("Длина и ширина должны быть положительными числами!");
	this->width = width;
	this->height = height;

	cells = std::make_unique<cell_row[]>(this->height);
	for (size_t i = 0; i < this->height; i++)
	{
		cells[i] = std::make_unique<cell_ptr[]>(this->width);
	}
}

Field::Field(const Field& other) : Field(other.width, other.height)
{
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			this->setCell(x, y, other.cells[y][x].get());
		}
	}
}

Field::Field(Field&& other) : width{other.width}, height{other.height}
{
	cells = std::move(other.cells);
}

void Field::setCell(size_t x, size_t y, Cell *cell)
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height) 
		throw std::runtime_error("Координаты не должны выходить за границы поля!");
	cells[y][x] = cell->createUniquePtr();
}

bool Field::onCellsAdded()
{
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			size_t draw_layer = 0; /* background layer */
			ActionAddDrawable act(this->getCell(x, y), draw_layer);
			this->getObserver().handleAction(act);
		}
	}
	return true;
}

Cell& Field::getCell(size_t x, size_t y) const
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height) 
		return *this->cells[0][0].get();

	return *this->cells[y][x].get();
}

Field& Field::operator =(const Field& other)
{
	if (&other == this)
		return *this;

	this->width = other.width;
	this->height = other.height;

	cells = std::make_unique<cell_row[]>(this->height);
	for (size_t i = 0; i < this->height; i++)
	{
		cells[i] = std::make_unique<cell_ptr[]>(this->width);
	}
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			this->setCell(x, y, other.cells[y][x].get());
		}
	}

	return *this;
}

Field& Field::operator =(Field&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->width, other.width);
	std::swap(this->height, other.height);
	std::swap(this->cells, other.cells);

	return *this;
}

size_t Field::getHeight() const
{
	return this->height;
}

size_t Field::getWidth() const
{
	return this->width;
}

void Field::setStart(const std::pair<size_t, size_t>& start)
{
	this->start_cell.first  = start.first;
	this->start_cell.second = start.second;
}

void Field::setEnd(const std::pair<size_t, size_t>& end)
{
	this->end_cell.first  = end.first;
	this->end_cell.second = end.second;
}


void Field::setStart(size_t x, size_t y)
{
	this->start_cell.first  = x;
	this->start_cell.second = y;
}

void Field::setEnd(size_t x, size_t y)
{
	this->end_cell.first  = x;
	this->end_cell.second = y;
}

const std::pair<size_t, size_t>& Field::getStart() const
{
	return this->start_cell;
}

const std::pair<size_t, size_t>& Field::getEnd() const
{
	return this->end_cell;
}

Field::iterator::iterator(
	Field& _field,
	std::pair<size_t, size_t> cursor_position
): field{_field}
{
	this->cursor_x = cursor_position.first;
	this->cursor_y = cursor_position.second;
}

Field::iterator& Field::iterator::operator ++()
{
	if (!(this->cursor_y == this->field.getHeight()))
		this->cursor_x++;
	if (this->cursor_x == this->field.getWidth())
	{
		this->cursor_x = 0;
		this->cursor_y++;
	}
	return *this;
}

Field::iterator Field::iterator::operator ++(int)
{
	Field::iterator oldValue = *this;
	
	if (!(this->cursor_y == this->field.getHeight()))
		this->cursor_x++;
	if (this->cursor_x == this->field.getWidth())
	{
		this->cursor_x = 0;
		this->cursor_y++;
	}

	return oldValue;
}

bool Field::iterator::operator ==(const iterator& other) const
{
	return this->cursor_x == other.cursor_x && 
		this->cursor_y == other.cursor_y;
}

bool Field::iterator::operator !=(const iterator& other) const
{
	return !(this->cursor_x == other.cursor_x && 
		this->cursor_y == other.cursor_y);
}

Cell& Field::iterator::operator *() const
{
	return this->field.getCell(this->cursor_x, this->cursor_y);
}

Cell* Field::iterator::operator ->() const
{
	return &this->field.getCell(this->cursor_x, this->cursor_y);
}

Field::iterator Field::begin()
{
	return Field::iterator(*this);
}

Field::iterator Field::end()
{
	return Field::iterator(*this, {0, this->height});
}

std::string Field::getCurrentState() const
{
	std::stringstream buffer;
	buffer << "field_size=(" << this->width << "; " << this->height << ")" << std::endl;
	for (size_t y = 0; y < this->height; ++y)
	{
		for (size_t x = 0; x < this->width; ++x)
		{
			buffer << this->getCell(x, y).getCurrentState();
		}
	}
	return buffer.str();
}
