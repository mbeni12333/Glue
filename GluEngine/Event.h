#pragma once

#include "GLUE/Core.h"

#include <string>
#include <functional>

namespace GLUE {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, AppTick, AppUpdate, AppRender, KeyPressed,
		KeyReleased, MouseButtonPressed, MouseButtonReleased, MouseMouved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};



	class GLUE_API Event {
		friend class EventDispatcher;

		public: 
			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName(); }
		
			inline bool isInCategory(EventCategory category) {
				return GetCategoryFlags() & category;
			}
		protected: 
			bool m_handled = falsel;
	};


	class EventDispatcher {
		template<typename T> using EventFn = std::function<bool(T&)>l;
	public:
		EventDispatcher(Event& event):m_event(event) {}
		template<typename T> bool Dispatch(EventFn<T> func) {
			if (m_event.GetEventType() == T::GetStaticType()) {
				m_event.handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

}