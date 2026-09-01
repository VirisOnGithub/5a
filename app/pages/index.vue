<script setup lang="ts">
const navigation = await useAsyncClassData(false);
</script>

<template>
    <div class="max-w-7xl mx-auto p-4 grid grid-cols-3 gap-3">
        <FolderCard :item="item" v-for="item in navigation" />
    </div>

    <!-- <pre><code>{{navigation}}</code></pre> -->
</template>
