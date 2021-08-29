const methDemo = Vue.createApp({
	data() {
		return { count: 0 } // Start from where we like.
	},
	methods: {
		incrementCounter() {
			return this.count++
		}, // Default Counter Function
		click: _.debounce(function () { // Arrow Function won't work since its anonymous and doesn't have instance.
			return this.count++
		}, 500)
	}
})

const vm = methDemo.mount('#app')

console.log(vm.$data.count) // => 4
console.log(vm.count)       // => 4

vm.count = 5 // Assigning a value to vm.count will also update $data.count
console.log(vm.$data.count) // => 5

vm.$data.count = 6 // ... and vice-versa
console.log(vm.count) // => 6

// # App Component Style

const appData = { // # This is expected to be a data container after parse.
	// data() {
	// 	return {
	// 		count: 0
	// 	}
	// }
} // ! The problem is that, I don't know how to access its function from the component.

const appDemo = Vue.createApp(appData)

appDemo.component("save-button", {
	created() {
		this.debouncedInstance = _.debounce(this.clickedButtonFunc, 500)
	},
	data () {
		return {
			count: 0
		}
	},
	unmounted() {
		this.debouncedInstance.cancel()
	},
	methods: {
		clickedButtonFunc() {
			return this.count++
		}
	},
	template: `<button @click="debouncedInstance">Click To Increment {{ !count ? "" : "(" + count + ")" }}</button>`
})


appDemo.mount("#app-component")